#include "texture.h"

texture::texture()
{
}

void texture::loadTexture(QString f,char* lien)
  {/*QString str(lien);
    QFileInfo fileInf(str);
    QString filePath = "/home/gtsi/Documents/opengl/build-testopengl-Desktop-Debug/";//fileInf.absolutePath()+"/";
    */
    QImage buf_tuile;

       QImage tuile;

       buf_tuile.load("tuile1.bmp");
       tuile = QGLWidget::convertToGLFormat(buf_tuile);

       glGenTextures(1, &_texture[0]);
        glBindTexture( GL_TEXTURE_2D, _texture[0] );
       glTexImage2D(GL_TEXTURE_2D, 0, 3, tuile.width(), tuile.height(),
           0, GL_RGB, GL_UNSIGNED_BYTE, tuile.bits());


       glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


  }
QMap<QString,GLuint> texture::getTex(){
//    return _texture;
}
  void texture::applyTexture(QString url)
  {
//      if(!_texture.contains(url))
//      {
////          loadTexture(url);
//      }
//      glBindTexture( GL_TEXTURE_2D, _texture[url]);
  }
