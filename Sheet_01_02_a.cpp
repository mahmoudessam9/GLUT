#include <GL/glut.h>

void SetupRC() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glLineWidth(4.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(400.0f, 400.0f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL Blue Line");

	SetupRC();
	glutDisplayFunc(RenderScene);
	glutMainLoop();
	return 0;
}
