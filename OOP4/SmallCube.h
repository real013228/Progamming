//
// Created by real0 on 09.05.2022.
//

#ifndef OOP4_SMALLCUBE_H
#define OOP4_SMALLCUBE_H
#define FACESCOUNT 6
#include "GL//glut.h"
#include <iostream>

class SmallCube {
private:
    unsigned int faces[FACESCOUNT]{}; //верх, низ, спереди, сзади, слева, справа
public:
    GLfloat size_;

    SmallCube() {
        for (unsigned int &face: faces) {
            face = 0;
        }
        size_ = 0;
    }

    SmallCube(double size, const unsigned int *colors) {
        size_ = size;
        for (size_t i = 0; i < FACESCOUNT; ++i) {
            faces[i] = colors[i];
            std::cout << faces[i] << '\n';
        }
    }

    void setColor(int face, unsigned int color) {
        this->faces[face] = color;
    }

    void rotateRight(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            unsigned int tmp = faces[3];
            faces[3] = faces[0];
            faces[0] = faces[2];
            faces[2] = faces[1];
            faces[1] = tmp;
        }
    }

    void rotateLeft(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            rotateRight(3);
        }
    }

    void rotateUp(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            unsigned int tmp = faces[2];
            faces[2] = faces[5];
            faces[5] = faces[3];
            faces[3] = faces[4];
            faces[4] = tmp;
        }
    }

    void rotateDown(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            rotateUp(3);
        }
    }

    void rotateFront(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            unsigned int tmp = faces[0];
            faces[0] = faces[4];
            faces[4] = faces[1];
            faces[1] = faces[5];
            faces[5] = tmp;
        }
    }

    void rotateBack(int count = 1) {
        for (size_t i = 0; i < count; ++i) {
            rotateFront(3);
        }
    }

    unsigned char *at(int i) {
        // разбиваем color[i] на 3 составляющих
        // например для 0xFF0000 RGB(FF, 0, 00) - красный цвет;
        _color[0] = faces[i] >> 16;
        _color[1] = faces[i] >> 8;
        _color[2] = faces[i];
        return _color;
    }

    void draw() {
        glPushMatrix();
        glTranslatef(0, size_, 0);//верх
        glBegin(GL_QUADS);
        glColor3ubv(at(0));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glTranslatef(0, -2 * size_, 0);//низ
        glBegin(GL_QUADS);
        glColor3ubv(at(1));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glTranslatef(0, size_, 0); //спереди
        glBegin(GL_QUADS);
        glColor3ubv(at(2));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glTranslatef(2 * size_, 0, 0);//сзади
        glBegin(GL_QUADS);
        glColor3ubv(at(3));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glTranslatef(-3 * size_, 0, 0);//слева
        glBegin(GL_QUADS);
        glColor3ubv(at(4));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glTranslatef(2 * size_, 0, 0);//справа
        glBegin(GL_QUADS);
        glColor3ubv(at(5));
        glVertex2f(0, 0);
        glVertex2f(size_, 0);
        glVertex2f(size_, size_);
        glVertex2f(0, size_);
        glEnd();
        glPopMatrix();
    }

    unsigned int *getFaces() {
        return faces;
    }

private:
    unsigned char _color[4]{};
};

#endif //OOP4_SMALLCUBE_H
