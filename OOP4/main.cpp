#include "Cube.h"
#include <ctime>
#include <cstdlib>
#include "GL/glut.h"
#include <iostream>
#include <vector>
#include <fstream>
#define outPath "C:/Users/real0/CLionProjects/OOP4/output.txt"
//                    (верх,_____низ,____впереди,___сзади,_____лево,_____право)
unsigned int c[6] = {0xFFFFFF, 0xFFFF00, 0x00FF00, 0x0000FF, 0xFFA500, 0xFF0000};

//Data
const std::string inPath = R"(C:\Users\real0\CLionProjects\OOP4\input.txt)";
static Cube cube(1, c);
SmallCube smallCube(1, c);
int timerOn = 0;
float x_pos = 0;
//***************************
void reading();
void display();

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    std::cout << key << '\n';
    switch (key) {
        case 114:
            cube.rotateRight();
            break;
        case 108:
            cube.rotateLeft();
            break;
        case 117:
            cube.rotateUp();
            break;
        case 100:
            cube.rotateDown();
            break;
        case 102:
            cube.rotateFront();
            break;
        case 98:
            cube.rotateBack();
            break;
        case 32:
            exit(0);
        case 48:
            cube.rotateUp(3);
            break;
        case 49:
            cube.rotateDown(3);
            break;
        case 50:
            cube.rotateFront(3);
            break;
        case 51:
            cube.rotateBack(3);
            break;
        case 52:
            cube.rotateLeft(3);
            break;
        case 53:
            cube.rotateRight(3);
            break;
        default:
            std::cout << "click to the right button\n";
            
    }
}

void solvingDraw() {
    if(!cube.solveScramble.empty()) {
        std::string str = cube.solveScramble.front();
        cube.solveScramble.erase(cube.solveScramble.begin());
        if (str == "U") {
            cube.rotateUp();
        } else if (str == "D") {
            cube.rotateDown();
        } else if (str == "F") {
            cube.rotateFront();
        } else if (str == "B") {
            cube.rotateBack();
        } else if (str == "L") {
            cube.rotateLeft();
        } else if (str == "R") {
            cube.rotateRight();
        } else if (str == "U\'") {
            cube.rotateUp(3);
        } else if (str == "D\'") {
            cube.rotateDown(3);
        } else if (str == "F\'") {
            cube.rotateFront(3);
        } else if (str == "B\'") {
            cube.rotateBack(3);
        } else if (str == "L\'") {
            cube.rotateLeft(3);
        } else if (str == "R\'") {
            cube.rotateRight(3);
        } else if (str == "U2") {
            cube.rotateUp(2);
        } else if (str == "D2") {
            cube.rotateDown(2);
        } else if (str == "F2") {
            cube.rotateFront(2);
        } else if (str == "B2") {
            cube.rotateBack(2);
        } else if (str == "L2") {
            cube.rotateLeft(2);
        } else if (str == "R2") {
            cube.rotateRight(2);
        }
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT );
    glLoadIdentity();
    cube.setRandomScramble();
    cube.solveCross();
    cube.solveFirstLayer();
    cube.solveSecondLayer();
    cube.solveUpperCross();
    cube.solveUpperCorners();
    cube.lastPiwPaws();
    cube.draw();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.7, 1, 0.7, 0);
}

int main(int argc, char **argv) {
//    cube.setPosition(inPath);
//    cube.solveCross();
//    cube.solveFirstLayer();
//    cube.solveSecondLayer();
//    cube.solveUpperCross();
//    cube.solveUpperCorners();
//    cube.lastPiwPaws();
//    cube.setPosition(inPath);
//****************************
//    cube.setPosition(outPath);
//    cube.setRandomScramble();
//    cube.solveCross();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1080, 1080);
    glutInitWindowPosition(1, 1);
    glutCreateWindow("Cube");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}