#ifndef TEXTURE_H
#define TEXTURE_H

#include <QImage>
#include <QString>
#include <QtOpenGL>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
class texture
{
public:
    texture();
    void loadTexture(QString f, char *lien);
     void applyTexture(QString url);
     QMap<QString,GLuint> getTex();
private:
     QString fileName;
     QString filePath;
//     QMap<QString,GLuint> _texture;
     GLuint _texture[1];
};

#endif // TEXTURE_H
