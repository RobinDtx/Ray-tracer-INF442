/*
 * Camera.h
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "Vector.h"

class Camera {
	public:
		Camera();
		Camera(int heigh, int width);
		Camera(Vector* eye, Vector* target, Vector* orientation);
		Camera(Vector* eye, Vector* target, Vector* orientation, int heigh, int width);
		virtual ~Camera();

		const Vector* getEye() const;
		const Vector* getTarget() const;
		const Vector* getOrientation() const;
		int getHeigh() const;
		int getWidth() const;

		void setEye(Vector* eye);
		void setTarget(Vector* target);
		void setOrientation(Vector* orientation);
		void setHeigh(int heigh);
		void setWidth(int width);

	private:
		int heigh;
		int width;

		Vector eye;
		Vector target;
		Vector orientation;

};

#endif /* CAMERA_H_ */
