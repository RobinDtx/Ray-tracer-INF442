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
		Camera(double heigh, double width);
		Camera(Vector* eye, Vector* target, Vector* orientation);
		Camera(Vector* eye, Vector* target, Vector* orientation, double heigh, double width);
		virtual ~Camera();

		const Vector* getEye() const;
		const Vector* getTarget() const;
		const Vector* getOrientation() const;
		double getHeigh() const;
		double getWidth() const;

		void setEye(Vector* eye);
		void setTarget(Vector* target);
		void setOrientation(Vector* orientation);
		void setHeigh(double heigh);
		void setWidth(double width);

	private:
		double heigh;
		double width;

		Vector eye;
		Vector target;
		Vector orientation;

};

#endif /* CAMERA_H_ */
