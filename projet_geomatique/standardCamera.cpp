#include "standardCamera.h"

#include <QWheelEvent>

using namespace qglviewer;

StandardCamera::StandardCamera()
{
  standard = true;
  orthoSize = 1.0;
}

float StandardCamera::zNear() const
{
  if (standard)
	return 5.0f;
  else
	return Camera::zNear();
}

float StandardCamera::zFar() const
{
  if (standard)
	return 1000.0;
  else
	return Camera::zFar();
}

void StandardCamera::changeOrthoFrustumSize(int delta)
{
  if (delta > 0)
	orthoSize *= 2.5f;
  else
	orthoSize /= 2.5f;
}

void StandardCamera::getOrthoWidthHeight(GLdouble &halfWidth, GLdouble &halfHeight) const
{
  if (standard)
  {
	halfHeight = orthoSize;
	halfWidth = aspectRatio() * orthoSize;
  }
  else
	Camera::getOrthoWidthHeight(halfWidth, halfHeight);
}
