// Created by real0 on 13.05.2022.
//

#ifndef OOP4_CUBE_H
#define OOP4_CUBE_H
#include "SmallCube.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#define GOD_NUMBER 20
#define WHITE_SIDE 16777215
#define YELLOW_SIDE 16776960
#define GREEN_SIDE 65280
#define BLUE_SIDE 255
#define ORANGE_SIDE 16753920
#define RED_SIDE 16711680


class Cube {
public:
    unsigned int faces_[6]{};
    SmallCube cube_[3][3][3];
    std::vector<unsigned int> scramble;
    std::vector<std::string > solveScramble;
public:
    double size_{};

    Cube() = default;

    Cube(double size_, unsigned int *colors) {
        setSolvedPosition(size_, colors);
    }

    void rotateRight(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[2][0][0].rotateRight();
            SmallCube tmp1 = cube_[2][0][0];
            cube_[2][2][0].rotateRight();
            cube_[2][0][0] = cube_[2][2][0];
            cube_[2][2][2].rotateRight();
            cube_[2][2][0] = cube_[2][2][2];
            cube_[2][0][2].rotateRight();
            cube_[2][2][2] = cube_[2][0][2];
            cube_[2][0][2] = tmp1;
            //Edges rotating
            cube_[2][0][1].rotateRight();
            SmallCube tmp2 = cube_[2][0][1];
            cube_[2][1][0].rotateRight();
            cube_[2][0][1] = cube_[2][1][0];
            cube_[2][2][1].rotateRight();
            cube_[2][1][0] = cube_[2][2][1];
            cube_[2][1][2].rotateRight();
            cube_[2][2][1] = cube_[2][1][2];
            cube_[2][1][2] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("R");
        } else if (count == 2) {
            solveScramble.emplace_back("R2");
        } else if (count == 3) {
            solveScramble.emplace_back("R\'");
        }
    }

    void rotateLeft(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[0][0][0].rotateLeft();
            SmallCube tmp1 = cube_[0][0][0];
            cube_[0][0][2].rotateLeft();
            cube_[0][0][0] = cube_[0][0][2];
            cube_[0][2][2].rotateLeft();
            cube_[0][0][2] = cube_[0][2][2];
            cube_[0][2][0].rotateLeft();
            cube_[0][2][2] = cube_[0][2][0];
            cube_[0][2][0] = tmp1;
            //Edges rotating
            cube_[0][0][1].rotateLeft();
            SmallCube tmp2 = cube_[0][0][1];
            cube_[0][1][2].rotateLeft();
            cube_[0][0][1] = cube_[0][1][2];
            cube_[0][2][1].rotateLeft();
            cube_[0][1][2] = cube_[0][2][1];
            cube_[0][1][0].rotateLeft();
            cube_[0][2][1] = cube_[0][1][0];
            cube_[0][1][0] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("L");
        } else if (count == 2) {
            solveScramble.emplace_back("L2");
        } else if (count == 3) {
            solveScramble.emplace_back("L\'");
        }
    }

    void rotateUp(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[0][0][2].rotateUp();
            SmallCube tmp1 = cube_[0][0][2];
            cube_[2][0][2].rotateUp();
            cube_[0][0][2] = cube_[2][0][2];
            cube_[2][2][2].rotateUp();
            cube_[2][0][2] = cube_[2][2][2];
            cube_[0][2][2].rotateUp();
            cube_[2][2][2] = cube_[0][2][2];
            cube_[0][2][2] = tmp1;
            //Edges rotating
            cube_[1][0][2].rotateUp();
            SmallCube tmp2 = cube_[1][0][2];
            cube_[2][1][2].rotateUp();
            cube_[1][0][2] = cube_[2][1][2];
            cube_[1][2][2].rotateUp();
            cube_[2][1][2] = cube_[1][2][2];
            cube_[0][1][2].rotateUp();
            cube_[1][2][2] = cube_[0][1][2];
            cube_[0][1][2] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("U");
        } else if (count == 2) {
            solveScramble.emplace_back("U2");
        } else if (count == 3) {
            solveScramble.emplace_back("U\'");
        }
    }

    void rotateDown(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[2][0][0].rotateDown();
            SmallCube tmp1 = cube_[2][0][0];
            cube_[0][0][0].rotateDown();
            cube_[2][0][0] = cube_[0][0][0];
            cube_[0][2][0].rotateDown();
            cube_[0][0][0] = cube_[0][2][0];
            cube_[2][2][0].rotateDown();
            cube_[0][2][0] = cube_[2][2][0];
            cube_[2][2][0] = tmp1;
            //Edges rotating
            cube_[1][0][0].rotateDown();
            SmallCube tmp2 = cube_[1][0][0];
            cube_[0][1][0].rotateDown();
            cube_[1][0][0] = cube_[0][1][0];
            cube_[1][2][0].rotateDown();
            cube_[0][1][0] = cube_[1][2][0];
            cube_[2][1][0].rotateDown();
            cube_[1][2][0] = cube_[2][1][0];
            cube_[2][1][0] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("D");
        } else if (count == 2) {
            solveScramble.emplace_back("D2");
        } else if (count == 3) {
            solveScramble.emplace_back("D\'");
        }
    }

    void rotateFront(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[2][0][2].rotateFront();
            SmallCube tmp1 = cube_[2][0][2];
            cube_[0][0][2].rotateFront();
            cube_[2][0][2] = cube_[0][0][2];
            cube_[0][0][0].rotateFront();
            cube_[0][0][2] = cube_[0][0][0];
            cube_[2][0][0].rotateFront();
            cube_[0][0][0] = cube_[2][0][0];
            cube_[2][0][0] = tmp1;
            //Edges rotating
            cube_[1][0][2].rotateFront();
            SmallCube tmp2 = cube_[1][0][2];
            cube_[0][0][1].rotateFront();
            cube_[1][0][2] = cube_[0][0][1];
            cube_[1][0][0].rotateFront();
            cube_[0][0][1] = cube_[1][0][0];
            cube_[2][0][1].rotateFront();
            cube_[1][0][0] = cube_[2][0][1];
            cube_[2][0][1] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("F");
        } else if (count == 2) {
            solveScramble.emplace_back("F2");
        } else if (count == 3) {
            solveScramble.emplace_back("F\'");
        }
    }

    void rotateBack(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            //Vertexes rotating
            cube_[0][2][2].rotateBack();
            SmallCube tmp1 = cube_[0][2][2];
            cube_[2][2][2].rotateBack();
            cube_[0][2][2] = cube_[2][2][2];
            cube_[2][2][0].rotateBack();
            cube_[2][2][2] = cube_[2][2][0];
            cube_[0][2][0].rotateBack();
            cube_[2][2][0] = cube_[0][2][0];
            cube_[0][2][0] = tmp1;
            //Edges rotating
            cube_[1][2][2].rotateBack();
            SmallCube tmp2 = cube_[1][2][2];
            cube_[2][2][1].rotateBack();
            cube_[1][2][2] = cube_[2][2][1];
            cube_[1][2][0].rotateBack();
            cube_[2][2][1] = cube_[1][2][0];
            cube_[0][2][1].rotateBack();
            cube_[1][2][0] = cube_[0][2][1];
            cube_[0][2][1] = tmp2;
        }
        if (count == 1) {
            solveScramble.emplace_back("B");
        } else if (count == 2) {
            solveScramble.emplace_back("B2");
        } else if (count == 3) {
            solveScramble.emplace_back("B\'");
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(0, 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][0].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][1].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][2].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][0][2].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][2].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][1].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][0].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][0][0].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][0][1].at(2));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//********************************

        glTranslatef(2 * GLfloat(size_ / 3), -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][0].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][1].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][2].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][1][2].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][2].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][1].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][0].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][1][0].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][1][1].at(5));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//*********************

        glTranslatef(2 * GLfloat(size_ / 3), -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][0].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][1].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][2].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][2][2].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][2].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][1].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][0].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][2][0].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][2][1].at(3));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//*********************

        glTranslatef(-10 * GLfloat(size_ / 3), -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][0].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][1].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][2].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][1][2].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][2].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][1].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][0].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][1][0].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][1][1].at(4));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//*********************
        glTranslatef(2 * GLfloat(size_ / 3), 2 * GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][1][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][2][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][1][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][0][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][1][2].at(0));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//******************************
        glTranslatef(-1 * GLfloat(size_ / 3), -7 * GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][2][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][1][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[0][0][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][0][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][0][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][1][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, -GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[2][2][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(-GLfloat(size_ / 3), 0, 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][2][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();

        glTranslatef(0, GLfloat(size_ / 3), 0);
        glBegin(GL_QUADS);
        glColor3ubv(cube_[1][1][0].at(1));
        glVertex2f(0, 0);
        glVertex2f(GLfloat(size_ / 3), 0);
        glVertex2f(GLfloat(size_ / 3), GLfloat(size_ / 3));
        glVertex2f(0, GLfloat(size_ / 3));
        glEnd();
//*********************
        glPopMatrix();
    }

    unsigned int randomGod() {
        std::srand(time(nullptr));
        static unsigned int seed = rand();

        // Берем стартовое число и, с его помощью, генерируем новое значение.
        // Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
        seed = (8253729 * seed + 2396403);

        // Берем стартовое число и возвращаем значение в диапазоне от 0 до 32767
        return seed % 6;
    }

    void setPosition(const std::string &path) {
        std::ifstream fin;
        std::string str;
        fin.open(path);
        if (!fin.is_open()) {
            std::cout << "file hadn't opened\n";
            return;
        } else {
            while (std::getline(fin, str)) {
                if (str == "U") {
                    this->rotateUp();
                    scramble.push_back(2);
                } else if (str == "D") {
                    this->rotateDown();
                    scramble.push_back(3);
                } else if (str == "F") {
                    this->rotateFront();
                    scramble.push_back(4);
                } else if (str == "B") {
                    this->rotateBack();
                    scramble.push_back(5);
                } else if (str == "L") {
                    this->rotateLeft();
                    scramble.push_back(1);
                } else if (str == "R") {
                    this->rotateRight();
                    scramble.push_back(0);
                } else if (str == "U\'") {
                    this->rotateUp(3);
                    scramble.push_back(14);
                } else if (str == "D\'") {
                    this->rotateDown(3);
                    scramble.push_back(15);
                } else if (str == "F\'") {
                    this->rotateFront(3);
                    scramble.push_back(16);
                } else if (str == "B\'") {
                    this->rotateBack(3);
                    scramble.push_back(17);
                } else if (str == "L\'") {
                    this->rotateLeft(3);
                    scramble.push_back(13);
                } else if (str == "R\'") {
                    this->rotateRight(3);
                    scramble.push_back(12);
                } else if (str == "U2") {
                    this->rotateUp(2);
                    scramble.push_back(7);
                } else if (str == "D2") {
                    this->rotateDown(2);
                    scramble.push_back(8);
                } else if (str == "F2") {
                    this->rotateFront(2);
                    scramble.push_back(9);
                } else if (str == "B2") {
                    this->rotateBack(2);
                    scramble.push_back(10);
                } else if (str == "L2") {
                    this->rotateLeft(2);
                    scramble.push_back(11);
                } else if (str == "R2") {
                    this->rotateRight(2);
                    scramble.push_back(6);
                }
                solveScramble.pop_back();
            }
        }

        fin.close();
    }

    void setRandomScramble() {
        for (size_t i = 0; i < GOD_NUMBER; ++i) {
            unsigned int rot = randomGod();
            scramble.push_back(rot);
            switch (rot) {
                case 0:
                    this->rotateRight();
                    break;
                case 1:
                    this->rotateLeft();
                    break;
                case 2:
                    this->rotateUp();
                    break;
                case 3:
                    this->rotateDown();
                    break;
                case 4:
                    this->rotateFront();
                    break;
                case 5:
                    this->rotateBack();
                    break;
                case 6:
                    this->rotateRight(2);
                    break;
                case 7:
                    this->rotateUp(2);
                    break;
                case 8:
                    this->rotateDown(2);
                    break;
                case 9:
                    this->rotateFront(2);
                    break;
                case 10:
                    this->rotateBack(2);
                    break;
                case 11:
                    this->rotateLeft(2);
                    break;
                case 12:
                    this->rotateRight(3);
                    break;
                case 13:
                    this->rotateLeft(3);
                    break;
                case 14:
                    this->rotateUp(3);
                    break;
                case 15:
                    this->rotateDown(3);
                    break;
                case 16:
                    this->rotateFront(3);
                    break;
                case 17:
                    this->rotateBack(3);
                    break;
                default:
                    std::cout << "impossible case xD\n";
            }
            solveScramble.pop_back();
        }
    }

    void setSolvedPosition(double size, unsigned int *color) {
        for (size_t i = 0; i < sizeof(faces_); ++i) {
            faces_[i] = 0;
        }
        this->size_ = size;

        for (size_t i = 0; i < 6; i++) {
            this->faces_[i] = color[i];
        }
        // верх
        for (auto &i: cube_) {
            for (auto &j: i) {
                j[2].setColor(0, color[0]);
            }
        }
        // низ
        for (auto &i: cube_) {
            for (auto &j: i) {
                j[0].setColor(1, color[1]);
            }
        }
        // спереди
        for (size_t k = 0; k < 3; k++) {
            for (auto &j: cube_) {
                j[0][k].setColor(2, color[2]);
            }
        }
        // сзади
        for (size_t k = 0; k < 3; k++) {
            for (auto &j: cube_) {
                j[2][k].setColor(3, color[3]);
            }
        }
        // слева
        for (size_t i = 0; i < 3; i++) {
            for (size_t k = 0; k < 3; k++) {
                cube_[0][k][i].setColor(4, color[4]);
            }
        }
        // справа
        for (size_t i = 0; i < 3; i++) {
            for (size_t k = 0; k < 3; k++) {
                cube_[2][k][i].setColor(5, color[5]);
            }
        }
    }

    bool crossFitness() {
        if (
//        if (this->cube_[0][0][0].getFaces()[1] == YELLOW_SIDE &&
//                this->cube_[0][0][0].getFaces()[4] == ORANGE_SIDE &&
//                    this->cube_[0][0][0].getFaces()[2] == GREEN_SIDE &&
//            this->cube_[2][0][0].getFaces()[2] == GREEN_SIDE &&
//                this->cube_[2][0][0].getFaces()[5] == RED_SIDE &&
//                    this->cube_[2][0][0].getFaces()[1] == YELLOW_SIDE &&
//            this->cube_[2][2][0].getFaces()[5] == RED_SIDE &&
//                this->cube_[2][2][0].getFaces()[1] == YELLOW_SIDE &&
//                    this->cube_[2][2][0].getFaces()[3] == BLUE_SIDE &&
//            this->cube_[0][2][0].getFaces()[4] == ORANGE_SIDE &&
//                this->cube_[0][2][0].getFaces()[3] == BLUE_SIDE &&
//                    this->cube_[0][2][0].getFaces()[1] == YELLOW_SIDE &&
//            this->cube_[1][0][0].getFaces()[2] == GREEN_SIDE &&
                this->cube_[1][0][0].getFaces()[1] == YELLOW_SIDE &&
                //            this->cube_[2][1][0].getFaces()[5] == RED_SIDE &&
                this->cube_[2][1][0].getFaces()[1] == YELLOW_SIDE &&
                //            this->cube_[1][2][0].getFaces()[3] == BLUE_SIDE &&
                this->cube_[1][2][0].getFaces()[1] == YELLOW_SIDE &&
                //            this->cube_[0][1][0].getFaces()[4] == ORANGE_SIDE &&
                this->cube_[0][1][0].getFaces()[1] == YELLOW_SIDE &&
                this->cube_[1][1][0].getFaces()[1] == YELLOW_SIDE) {
            return true;
        }
        return false;
    }

    bool firstLayerFitness() {
        if (this->cube_[0][0][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[0][0][0].getFaces()[4] == ORANGE_SIDE &&
            this->cube_[0][0][0].getFaces()[2] == GREEN_SIDE &&
            this->cube_[2][0][0].getFaces()[2] == GREEN_SIDE &&
            this->cube_[2][0][0].getFaces()[5] == RED_SIDE &&
            this->cube_[2][0][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[2][2][0].getFaces()[5] == RED_SIDE &&
            this->cube_[2][2][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[2][2][0].getFaces()[3] == BLUE_SIDE &&
            this->cube_[0][2][0].getFaces()[4] == ORANGE_SIDE &&
            this->cube_[0][2][0].getFaces()[3] == BLUE_SIDE &&
            this->cube_[0][2][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[1][0][0].getFaces()[2] == GREEN_SIDE &&
            this->cube_[1][0][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[2][1][0].getFaces()[5] == RED_SIDE &&
            this->cube_[2][1][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[1][2][0].getFaces()[3] == BLUE_SIDE &&
            this->cube_[1][2][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[0][1][0].getFaces()[4] == ORANGE_SIDE &&
            this->cube_[0][1][0].getFaces()[1] == YELLOW_SIDE &&
            this->cube_[1][1][0].getFaces()[1] == YELLOW_SIDE) {
            return true;
        }
        return false;
    }

    bool secondLayerFitness() {
        if (firstLayerFitness()) {
            if (cube_[0][0][1].getFaces()[2] == cube_[1][0][1].getFaces()[2] &&
                cube_[0][0][1].getFaces()[4] == cube_[0][1][1].getFaces()[4] &&
                cube_[2][0][1].getFaces()[2] == cube_[1][0][1].getFaces()[2] &&
                cube_[2][0][1].getFaces()[5] == cube_[2][1][1].getFaces()[5] &&
                cube_[2][2][1].getFaces()[5] == cube_[2][1][1].getFaces()[5] &&
                cube_[2][2][1].getFaces()[3] == cube_[1][2][1].getFaces()[3] &&
                cube_[0][2][1].getFaces()[3] == cube_[1][2][1].getFaces()[3] &&
                cube_[0][2][1].getFaces()[4] == cube_[0][1][1].getFaces()[4]) {
                return true;
            }
        }
        return false;
    }

    bool upperCrossWithoutEdgesFitness() {
        if (cube_[0][1][2].getFaces()[0] == WHITE_SIDE && cube_[1][2][2].getFaces()[0] == WHITE_SIDE &&
            cube_[2][1][2].getFaces()[0] == WHITE_SIDE && cube_[1][0][2].getFaces()[0] == WHITE_SIDE) {
            return true;
        }
        return false;
    }

    bool upperCrossFitness() {
        if (secondLayerFitness() &&
            cube_[1][0][2].getFaces()[2] == GREEN_SIDE &&
            cube_[2][1][2].getFaces()[5] == RED_SIDE &&
            cube_[1][2][2].getFaces()[3] == BLUE_SIDE &&
            cube_[0][1][2].getFaces()[4] == ORANGE_SIDE
            ||
            cube_[1][0][2].getFaces()[2] == ORANGE_SIDE &&
            cube_[2][1][2].getFaces()[5] == GREEN_SIDE &&
            cube_[1][2][2].getFaces()[3] == RED_SIDE &&
            cube_[0][1][2].getFaces()[4] == BLUE_SIDE
            ||
            cube_[1][0][2].getFaces()[2] == BLUE_SIDE &&
            cube_[2][1][2].getFaces()[5] == ORANGE_SIDE &&
            cube_[1][2][2].getFaces()[3] == GREEN_SIDE &&
            cube_[0][1][2].getFaces()[4] == RED_SIDE
            ||
            cube_[1][0][2].getFaces()[2] == RED_SIDE &&
            cube_[2][1][2].getFaces()[5] == BLUE_SIDE &&
            cube_[1][2][2].getFaces()[3] == ORANGE_SIDE &&
            cube_[0][1][2].getFaces()[4] == GREEN_SIDE
                ) {
            return true;
        }
        return false;
    }

    bool upperCornersFitness() {
        if (upperCrossFitness() &&
            (cube_[0][0][2].getFaces()[0] == WHITE_SIDE &&
             cube_[0][0][2].getFaces()[2] == cube_[1][0][2].getFaces()[2] &&
             cube_[0][0][2].getFaces()[4] == cube_[0][1][2].getFaces()[4]
             ||
             cube_[0][0][2].getFaces()[0] == cube_[0][1][2].getFaces()[4] &&
             cube_[0][0][2].getFaces()[2] == WHITE_SIDE &&
             cube_[0][0][2].getFaces()[4] == cube_[1][0][2].getFaces()[2]
             ||
             cube_[0][0][2].getFaces()[0] == cube_[1][0][2].getFaces()[2] &&
             cube_[0][0][2].getFaces()[2] == cube_[0][1][2].getFaces()[4] &&
             cube_[0][0][2].getFaces()[4] == WHITE_SIDE)
            &&
            (cube_[2][0][2].getFaces()[0] == WHITE_SIDE &&
             cube_[2][0][2].getFaces()[2] == cube_[1][0][2].getFaces()[2] &&
             cube_[2][0][2].getFaces()[5] == cube_[2][1][2].getFaces()[5]
             ||
             cube_[2][0][2].getFaces()[0] == cube_[2][1][2].getFaces()[5] &&
             cube_[2][0][2].getFaces()[2] == WHITE_SIDE &&
             cube_[2][0][2].getFaces()[5] == cube_[1][0][2].getFaces()[2]
             ||
             cube_[2][0][2].getFaces()[0] == cube_[1][0][2].getFaces()[2] &&
             cube_[2][0][2].getFaces()[2] == cube_[2][1][2].getFaces()[5] &&
             cube_[2][0][2].getFaces()[5] == WHITE_SIDE)
            &&
            (cube_[2][2][2].getFaces()[0] == WHITE_SIDE &&
             cube_[2][2][2].getFaces()[3] == cube_[1][2][2].getFaces()[3] &&
             cube_[2][2][2].getFaces()[5] == cube_[2][1][2].getFaces()[5]
             ||
             cube_[2][2][2].getFaces()[0] == cube_[2][1][2].getFaces()[5] &&
             cube_[2][2][2].getFaces()[3] == WHITE_SIDE &&
             cube_[2][2][2].getFaces()[5] == cube_[1][2][2].getFaces()[3]
             ||
             cube_[2][2][2].getFaces()[0] == cube_[1][2][2].getFaces()[3] &&
             cube_[2][2][2].getFaces()[3] == cube_[2][1][2].getFaces()[5] &&
             cube_[2][2][2].getFaces()[5] == WHITE_SIDE)
            &&
            (cube_[0][2][2].getFaces()[0] == WHITE_SIDE &&
             cube_[0][2][2].getFaces()[3] == cube_[1][2][2].getFaces()[3] &&
             cube_[0][2][2].getFaces()[4] == cube_[0][1][2].getFaces()[4]
             ||
             cube_[0][2][2].getFaces()[0] == cube_[0][1][2].getFaces()[4] &&
             cube_[0][2][2].getFaces()[3] == WHITE_SIDE &&
             cube_[0][2][2].getFaces()[4] == cube_[1][2][2].getFaces()[3]
             ||
             cube_[0][2][2].getFaces()[0] == cube_[1][2][2].getFaces()[3] &&
             cube_[0][2][2].getFaces()[3] == cube_[0][1][2].getFaces()[4] &&
             cube_[0][2][2].getFaces()[4] == WHITE_SIDE)
                ) {
            return true;
        }
        return false;
    }

    bool upperLayerFitness() {
        if(cube_[0][0][2].getFaces()[0] == WHITE_SIDE &&
            cube_[2][0][2].getFaces()[0] == WHITE_SIDE &&
            cube_[2][2][2].getFaces()[0] == WHITE_SIDE &&
            cube_[0][2][2].getFaces()[0] == WHITE_SIDE) {
            return true;
        }
        return false;
    }

    bool cubeIsSolved() {
        if(crossFitness() && firstLayerFitness() && secondLayerFitness() && upperCornersFitness() && upperLayerFitness()
        && cube_[0][0][2].getFaces()[2] == GREEN_SIDE && cube_[1][0][2].getFaces()[2] == GREEN_SIDE && cube_[2][0][2].getFaces()[2] == GREEN_SIDE) {
            return true;
        }
        return false;
    }

    void upperPiwPaw() {
        rotateRight(3);
        rotateDown(3);
        rotateRight();
        rotateDown();
    }
    void crossEdgesSorting() {
        rotateLeft();
        rotateDown();
        rotateLeft(3);
        rotateDown();
        rotateLeft();
        rotateDown(2);
        rotateLeft(3);
        int safeCompNum = 0;
        while(this->cube_[1][0][0].getFaces()[2] != this->cube_[1][0][1].getFaces()[2] && safeCompNum++ < 4) {
            rotateDown();
        }
    }
    void piwPawRight(int cnt = 1) {
        for(size_t i = 0; i < cnt; ++i) {
            rotateRight();
            rotateUp();
            rotateRight(3);
            rotateUp(3);
        }
    }
    void piwPawLeft(int cnt = 1) {
        for(size_t i = 0; i < cnt; ++i) {
            rotateFront(3);
            rotateUp(3);
            rotateFront();
            rotateUp();
        }
    }
    void upperCrossEdgesSorting() {
        rotateRight();
        rotateUp();
        rotateRight(3);
        rotateUp();
        rotateRight();
        rotateUp(2);
        rotateRight(3);
    }
    void upperCornerSorting() {
        rotateRight();
        rotateUp(3);
        rotateLeft(3);
        rotateUp();
        rotateRight(3);
        rotateUp(3);
        rotateLeft();
        rotateUp();
    }
    void putTheEdge(char letter) {
        if(letter == 'r') {
            rotateUp(3);
            rotateLeft(3);
            rotateUp();
            rotateLeft();
            rotateUp();
            rotateFront();
            rotateUp(3);
            rotateFront(3);
        } else if(letter == 'l') {
            rotateUp();
            rotateRight();
            rotateUp(3);
            rotateRight(3);
            rotateUp(3);
            rotateFront(3);
            rotateUp();
            rotateFront();
        }
    }
    void solveCross() {
        if(this->cube_[1][0][0].getFaces()[2] == GREEN_SIDE &&
           this->cube_[1][0][0].getFaces()[1] == YELLOW_SIDE &&
           this->cube_[2][1][0].getFaces()[5] == RED_SIDE &&
           this->cube_[2][1][0].getFaces()[1] == YELLOW_SIDE &&
           this->cube_[1][2][0].getFaces()[3] == BLUE_SIDE &&
           this->cube_[1][2][0].getFaces()[1] == YELLOW_SIDE &&
           this->cube_[0][1][0].getFaces()[4] == ORANGE_SIDE &&
           this->cube_[0][1][0].getFaces()[1] == YELLOW_SIDE) {
            return;
        } else {
            //only one move
            int tries = 0;
            while (tries < 4 &&
                   (cube_[1][0][2].getFaces()[0] != YELLOW_SIDE || cube_[2][1][2].getFaces()[0] != YELLOW_SIDE ||
                    cube_[1][2][2].getFaces()[0] != YELLOW_SIDE || cube_[0][1][2].getFaces()[0] != YELLOW_SIDE)) {
                if (cube_[2][0][1].getFaces()[2] == YELLOW_SIDE) {
                    while (cube_[2][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateRight();
                }
                if (cube_[2][0][1].getFaces()[5] == YELLOW_SIDE) {
                    while (cube_[1][0][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateFront(3);
                }

                if (cube_[0][0][1].getFaces()[2] == YELLOW_SIDE) {
                    while (cube_[0][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateLeft(3);
                }
                if (cube_[0][0][1].getFaces()[4] == YELLOW_SIDE) {
                    while (cube_[1][0][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateFront();
                }

                if (cube_[0][2][1].getFaces()[3] == YELLOW_SIDE) {
                    while (cube_[0][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateLeft();
                }
                if (cube_[0][2][1].getFaces()[4] == YELLOW_SIDE) {
                    while (cube_[1][2][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateBack(3);
                }

                if (cube_[2][2][1].getFaces()[3] == YELLOW_SIDE) {
                    while (cube_[2][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateRight(3);
                }
                if (cube_[2][2][1].getFaces()[5] == YELLOW_SIDE) {
                    while (cube_[1][2][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateBack();
                }
                //DOWN 2 moves
                if (cube_[1][0][0].getFaces()[1] == YELLOW_SIDE) {
                    while (cube_[1][0][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateFront(2);
                }
                if (cube_[2][1][0].getFaces()[1] == YELLOW_SIDE) {
                    while (cube_[2][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateRight(2);
                }
                if (cube_[1][2][0].getFaces()[1] == YELLOW_SIDE) {
                    while (cube_[1][2][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateBack(2);
                }
                if (cube_[0][1][0].getFaces()[1] == YELLOW_SIDE) {
                    while (cube_[0][1][2].getFaces()[0] == YELLOW_SIDE) {
                        rotateUp();
                    }
                    rotateLeft(2);
                }
                //BAD CASES
                int cnt = 0;
                while (cnt++ < 8) {
                    if (cube_[1][0][2].getFaces()[2] == YELLOW_SIDE) {
                        rotateFront();
                        rotateUp(3);
                        rotateRight();
                        rotateUp();
                    }
                    rotateUp();
                }
                cnt = 0;
                while (cnt++ <= 8) {
                    if (cube_[1][0][0].getFaces()[2] == YELLOW_SIDE) {
                        while (cube_[1][0][2].getFaces()[0] == YELLOW_SIDE) {
                            rotateUp();
                        }
                        rotateFront();
                        rotateUp();
                        rotateLeft(3);
                        rotateUp(3);
                    }
                    rotateDown();
                }
                tries++;
            }
            while (cube_[1][0][2].getFaces()[2] != GREEN_SIDE) {
                rotateUp();
            }
            rotateFront(2);
            while (cube_[1][0][2].getFaces()[2] != RED_SIDE || cube_[1][0][2].getFaces()[0] != YELLOW_SIDE) {
                rotateUp();
            }
            rotateDown(3);
            rotateFront(2);
            while (cube_[1][0][2].getFaces()[2] != BLUE_SIDE || cube_[1][0][2].getFaces()[0] != YELLOW_SIDE) {
                rotateUp();
            }
            rotateDown(3);
            rotateFront(2);
            while (cube_[1][0][2].getFaces()[2] != ORANGE_SIDE || cube_[1][0][2].getFaces()[0] != YELLOW_SIDE) {
                rotateUp();
            }
            rotateDown(3);
            rotateFront(2);
            rotateDown(3);
        }
    }
    void solveFirstLayer() {
        while(!firstLayerFitness()) {
            for (size_t i = 0; i < 8; ++i) {
                int cnt = 0;
                if (cube_[2][0][2].getFaces()[2] == YELLOW_SIDE) {
                    while (cube_[2][0][2].getFaces()[0] != cube_[1][0][0].getFaces()[2] &&
                           cube_[2][0][2].getFaces()[5] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                        rotateDown();
                        cnt++;
                    }
                    rotateFront(3);
                    rotateUp(3);
                    rotateFront();
                    rotateUp();
                } else if (cube_[2][0][2].getFaces()[5] == YELLOW_SIDE) {
                    while (cube_[2][0][2].getFaces()[2] != cube_[1][0][0].getFaces()[2] &&
                           cube_[2][0][2].getFaces()[0] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                        rotateDown();
                        cnt++;
                    }
                    piwPawRight();
                } else if (cube_[2][0][2].getFaces()[0] == YELLOW_SIDE) {
                    while (cube_[2][0][2].getFaces()[5] != cube_[1][0][0].getFaces()[2] &&
                           cube_[2][0][2].getFaces()[2] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                        rotateDown();
                        cnt++;
                    }
                    piwPawRight(3);
                } else {
                    rotateUp();
                }
            }
            while (cube_[1][0][0].getFaces()[2] != GREEN_SIDE) {
                rotateDown();
            }
            if (firstLayerFitness()) {
                std::cout << "The first layer has been solved\n";
                return;
            } else {
                for (size_t i = 0; i < 8; ++i) {
                    int cnt = 0;
                    if (cube_[2][0][0].getFaces()[5] == YELLOW_SIDE) {
                        piwPawRight();
                        while (cube_[2][0][2].getFaces()[2] != cube_[1][0][0].getFaces()[2] &&
                               cube_[2][0][2].getFaces()[0] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                            rotateDown();
                            cnt++;
                        }
                        piwPawRight();
                    } else if (cube_[2][0][0].getFaces()[2] == YELLOW_SIDE) {
                        piwPawRight(3);
                        while (cube_[2][0][2].getFaces()[2] != cube_[1][0][0].getFaces()[2] &&
                               cube_[2][0][2].getFaces()[0] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                            rotateDown();
                            cnt++;
                        }
                        piwPawRight();
                    } else if (cube_[2][0][0].getFaces()[1] == YELLOW_SIDE &&
                               cube_[2][0][0].getFaces()[2] != cube_[1][0][0].getFaces()[2] &&
                               cube_[2][0][0].getFaces()[5] != cube_[2][1][0].getFaces()[5]) {
                        piwPawRight(5);
                        while (cube_[2][0][2].getFaces()[2] != cube_[1][0][0].getFaces()[2] &&
                               cube_[2][0][2].getFaces()[0] != cube_[2][1][0].getFaces()[5] && cnt < 4) {
                            rotateDown();
                            cnt++;
                        }
                    } else {
                        rotateDown();
                    }
                }
            }
            while (cube_[1][0][0].getFaces()[2] != GREEN_SIDE) {
                rotateDown();
            }
        }
        if (firstLayerFitness()) {
            std::cout << "The first layer has been solved\n";
            return;
        } else {
            std::cout << "something has wrong\n";
        }
    }
    void solveSecondLayer() {
        int safeNum = 0;
        if(secondLayerFitness()) {
//            std::cout << "The second layer has been solved\n";
            return;
        } else {
            while (!secondLayerFitness()) {
                safeNum++;
                for (size_t i = 0; i < 8; ++i) {
                    if (cube_[1][0][2].getFaces()[2] == cube_[1][0][0].getFaces()[2] && cube_[1][0][2].getFaces()[0] != WHITE_SIDE) {
                        if (cube_[1][0][2].getFaces()[0] == cube_[0][1][0].getFaces()[4]) {
                            putTheEdge('r');
                        } else if (cube_[1][0][2].getFaces()[0] == cube_[2][1][0].getFaces()[5]) {
                            putTheEdge('l');
                        }
                    } else if (cube_[2][1][2].getFaces()[5] == cube_[2][1][0].getFaces()[5] && cube_[2][1][2].getFaces()[0] != WHITE_SIDE) {
                        if (cube_[2][1][2].getFaces()[0] == cube_[1][0][0].getFaces()[2]) {
                            rotateUp(3);
                            rotateFront(3);
                            rotateUp();
                            rotateFront();
                            rotateUp();
                            rotateRight();
                            rotateUp(3);
                            rotateRight(3);
                        } else if (cube_[2][1][2].getFaces()[0] == cube_[1][2][0].getFaces()[3]) {
                            rotateUp();
                            rotateBack();
                            rotateUp(3);
                            rotateBack(3);
                            rotateUp(3);
                            rotateRight(3);
                            rotateUp();
                            rotateRight();
                        }
                    } else if (cube_[1][2][2].getFaces()[3] == cube_[1][2][0].getFaces()[3] && cube_[1][2][2].getFaces()[0] != WHITE_SIDE) {
                        if (cube_[1][2][2].getFaces()[0] == cube_[0][1][0].getFaces()[4]) {
                            rotateUp();
                            rotateLeft();
                            rotateUp(3);
                            rotateLeft(3);
                            rotateUp(3);
                            rotateBack(3);
                            rotateUp();
                            rotateBack();
                        } else if (cube_[1][2][2].getFaces()[0] == cube_[2][1][0].getFaces()[5]) {
                            rotateUp(3);
                            rotateRight(3);
                            rotateUp();
                            rotateRight();
                            rotateUp();
                            rotateBack();
                            rotateUp(3);
                            rotateBack(3);
                        }
                    } else if (cube_[0][1][2].getFaces()[4] == cube_[0][1][0].getFaces()[4] && cube_[0][1][2].getFaces()[0] != WHITE_SIDE) {
                        if (cube_[0][1][2].getFaces()[0] == cube_[1][2][0].getFaces()[3]) {
                            rotateUp(3);
                            rotateBack(3);
                            rotateUp();
                            rotateBack();
                            rotateUp();
                            rotateLeft();
                            rotateUp(3);
                            rotateLeft(3);
                        } else if (cube_[0][1][2].getFaces()[0] == cube_[1][0][0].getFaces()[2]) {
                            rotateUp();
                            rotateFront();
                            rotateUp(3);
                            rotateFront(3);
                            rotateUp(3);
                            rotateLeft(3);
                            rotateUp();
                            rotateLeft();
                        }
                    } else {
                        rotateUp();
                    }
                }
                if(cube_[2][0][1].getFaces()[2] != cube_[1][0][1].getFaces()[2] || cube_[2][0][1].getFaces()[5] != cube_[2][1][1].getFaces()[5]) {
                    piwPawRight();
                    piwPawLeft();
                    continue;
                }
                if(cube_[0][0][1].getFaces()[2] != cube_[1][0][1].getFaces()[2] || cube_[0][0][1].getFaces()[4] != cube_[0][1][1].getFaces()[4]) {
                    putTheEdge('r');
                    continue;
                }
                if(cube_[2][2][1].getFaces()[5] != cube_[2][1][1].getFaces()[5] || cube_[2][2][1].getFaces()[3] != cube_[1][2][1].getFaces()[3]) {
                    rotateRight(3);
                    rotateUp();
                    rotateRight();
                    rotateUp();
                    rotateBack();
                    rotateUp(3);
                    rotateBack(3);
                    continue;
                }
                if(cube_[0][2][1].getFaces()[4] != cube_[0][1][1].getFaces()[4] || cube_[0][2][1].getFaces()[3] != cube_[1][2][1].getFaces()[3]) {
                    rotateLeft();
                    rotateUp();
                    rotateLeft(3);
                    rotateUp(3);
                    rotateBack(3);
                    rotateUp(3);
                    rotateBack();
                    continue;
                }
            }
            if(secondLayerFitness()) {
                std::cout << "The second layer has been solved\n";
            } else {
                std::cout << "something has wrong\n";
            }
        }
    }
    void solveUpperCross() {
        if(!upperCrossFitness()) {
            if (cube_[0][1][2].getFaces()[0] != WHITE_SIDE && cube_[1][2][2].getFaces()[0] != WHITE_SIDE &&
                cube_[2][1][2].getFaces()[0] != WHITE_SIDE && cube_[1][0][2].getFaces()[0] != WHITE_SIDE) {
                rotateFront();
                piwPawRight(2);
                rotateFront(3);
                rotateUp();
                rotateFront();
                piwPawRight();
                rotateFront(3);
            }
            while(!upperCrossWithoutEdgesFitness()) {
                if (cube_[1][0][2].getFaces()[0] == WHITE_SIDE) {
                    if (cube_[1][2][2].getFaces()[0] == WHITE_SIDE) {
                        rotateUp();
                        rotateFront();
                        piwPawRight();
                        rotateFront(3);
                        break;
                    } else if (cube_[0][1][2].getFaces()[0] == WHITE_SIDE) {
                        rotateUp();
                        rotateFront();
                        piwPawRight(2);
                        rotateFront(3);
                        break;
                    } else if (cube_[2][1][2].getFaces()[0] == WHITE_SIDE) {
                        rotateUp(2);
                        rotateFront();
                        piwPawRight(2);
                        rotateFront(3);
                        break;
                    }
                } else {
                    rotateUp();
                }
            }
            while (cube_[1][0][2].getFaces()[2] != cube_[1][0][1].getFaces()[2]) {
                rotateUp();
            }
            if (!upperCrossFitness()) {
                if (cube_[2][1][2].getFaces()[5] == cube_[2][1][1].getFaces()[5]) {
                    rotateUp(3);
                    upperCrossEdgesSorting();
                    rotateUp(2);
                } else if (cube_[0][1][2].getFaces()[4] == cube_[0][1][1].getFaces()[4]) {
                    rotateUp(2);
                    upperCrossEdgesSorting();
                    rotateUp(3);
                } else if (cube_[1][2][2].getFaces()[3] == cube_[1][2][1].getFaces()[3]) {
                    upperCrossEdgesSorting();
                    rotateUp(3);
                    upperCrossEdgesSorting();
                    rotateUp(2);
                } else {
                    if (cube_[0][1][2].getFaces()[4] == cube_[2][1][1].getFaces()[5]) {
                        upperCrossEdgesSorting();
                    } else {
                        rotateLeft(3);
                        rotateUp(3);
                        rotateLeft();
                        rotateUp(3);
                        rotateLeft(3);
                        rotateUp(2);
                        rotateLeft();
                    }
                }
            } else {
                while(cube_[1][0][2].getFaces()[2] != GREEN_SIDE) {
                    rotateUp();
                }
                std::cout << "The upper cross has been solved\n";
            }
        }
        else {
            while(cube_[1][0][2].getFaces()[2] != GREEN_SIDE) {
                rotateUp();
            }
            std::cout << "The upper cross has been solved\n";
        }

    }
    void solveUpperCorners() {
        while(!upperCornersFitness()) {
            int safeNum = 0;
            while (!upperCornersFitness() && safeNum < 4) {
                safeNum++;
                if (cube_[0][0][2].getFaces()[0] == WHITE_SIDE &&
                    cube_[0][0][2].getFaces()[2] == cube_[1][0][2].getFaces()[2] &&
                    cube_[0][0][2].getFaces()[4] == cube_[0][1][2].getFaces()[4]
                    ||
                    cube_[0][0][2].getFaces()[0] == cube_[0][1][2].getFaces()[4] &&
                    cube_[0][0][2].getFaces()[2] == WHITE_SIDE &&
                    cube_[0][0][2].getFaces()[4] == cube_[1][0][2].getFaces()[2]
                    ||
                    cube_[0][0][2].getFaces()[0] == cube_[1][0][2].getFaces()[2] &&
                    cube_[0][0][2].getFaces()[2] == cube_[0][1][2].getFaces()[4] &&
                    cube_[0][0][2].getFaces()[4] == WHITE_SIDE) {
                    while (!upperCornersFitness())
                        upperCornerSorting();
                } else {
                    rotateUp();
                }
            }
            if (!upperCornersFitness()) {
                upperCornerSorting();
            }
        }
        while(cube_[1][0][2].getFaces()[2] != GREEN_SIDE) {
            rotateUp();
        }
    }
    void lastPiwPaws() {
        while(!upperLayerFitness()) {
            while(cube_[2][0][2].getFaces()[0] != WHITE_SIDE) {
                upperPiwPaw();
            }
            rotateUp();
        }
        while(cube_[1][0][2].getFaces()[2] != GREEN_SIDE) {
            rotateUp();
        }
    }
    void solveCrossRandomly() {
        int cnt = 0;
        srand(time(0));
        while(!this->crossFitness() && cnt++ < 100000) {
            unsigned int rot = this->randomGod();
            switch (rot) {
                case 0:
                    this->rotateRight();
                    break;
                case 1:
                    this->rotateLeft();
                    break;
                case 2:
                    this->rotateUp();
                    break;
                case 3:
                    this->rotateDown();
                    break;
                case 4:
                    this->rotateFront();
                    break;
                case 5:
                    this->rotateBack();
                    break;
                default:
                    std::cout << "impossible case xD\n";
            }
        }
        while (!(this->cube_[1][0][0].getFaces()[2] == GREEN_SIDE &&
                 this->cube_[1][0][0].getFaces()[1] == YELLOW_SIDE &&
                 this->cube_[2][1][0].getFaces()[5] == RED_SIDE &&
                 this->cube_[2][1][0].getFaces()[1] == YELLOW_SIDE &&
                 this->cube_[1][2][0].getFaces()[3] == BLUE_SIDE &&
                 this->cube_[1][2][0].getFaces()[1] == YELLOW_SIDE &&
                 this->cube_[0][1][0].getFaces()[4] == ORANGE_SIDE &&
                 this->cube_[0][1][0].getFaces()[1] == YELLOW_SIDE &&
                 this->cube_[1][1][0].getFaces()[1] == YELLOW_SIDE)) {
            while (this->cube_[1][0][0].getFaces()[2] != this->cube_[1][0][1].getFaces()[2]) {
                this->rotateDown();
            }
            if (this->cube_[0][1][0].getFaces()[4] == this->cube_[0][1][1].getFaces()[4]) {
                rotateDown(3);
                crossEdgesSorting();
            } else if (this->cube_[2][1][0].getFaces()[5] == this->cube_[2][1][1].getFaces()[5]) {
                rotateDown(2);
                crossEdgesSorting();
            } else if (this->cube_[1][2][0].getFaces()[3] == this->cube_[1][2][1].getFaces()[3]) {
                if (this->cube_[0][1][0].getFaces()[4] != this->cube_[0][1][1].getFaces()[4]) {
                    rotateRight(2);
                    rotateLeft(2);
                    rotateUp(2);
                    rotateRight(2);
                    rotateLeft(2);
                }
            } else {
                while (!(this->cube_[1][0][0].getFaces()[2] == GREEN_SIDE &&
                         this->cube_[1][0][0].getFaces()[1] == YELLOW_SIDE &&
                         this->cube_[2][1][0].getFaces()[5] == RED_SIDE &&
                         this->cube_[2][1][0].getFaces()[1] == YELLOW_SIDE &&
                         this->cube_[1][2][0].getFaces()[3] == BLUE_SIDE &&
                         this->cube_[1][2][0].getFaces()[1] == YELLOW_SIDE &&
                         this->cube_[0][1][0].getFaces()[4] == ORANGE_SIDE &&
                         this->cube_[0][1][0].getFaces()[1] == YELLOW_SIDE &&
                         this->cube_[1][1][0].getFaces()[1] == YELLOW_SIDE)) {
                    crossEdgesSorting();
                }
            }
        }
    }

};

//Cube a
//Cube b
//std::cout << (b == a);
#endif //OOP4_CUBE_H
