#include "Pong.cpp"

int width = 500;
int height = 300;
int frameInterval = 1000 / 60;

Pong pongGame(width, height);

void init() {
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D(0.0f, width, 0.0f, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	pongGame.draw();
	glutSwapBuffers();
}

void update(int value) {
	pongGame.play();

	// Call update again after interval
	glutTimerFunc(frameInterval, update, 0);

	// Call draw function again
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit (&argc, argv); // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition (50, 100); // Set top-left display-window position.
	glutInitWindowSize (width, height); // Set display-window width and height.
	glutCreateWindow ("Pong"); // Create display window.
	init(); // Execute initialization procedure.
	
	// Callbacks
	glutDisplayFunc(draw);
	glutTimerFunc(frameInterval, update, 0);

	glutMainLoop ( ); // Display everything and wait.
	return 0;
}