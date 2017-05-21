/*
 * Camera.h
 *
 *  Created on: 21 mai 2017
 *      Author: egoutierre
 */

#ifndef CAMERA_H_
#define CAMERA_H_

class Camera {
	public:
		Camera();
		virtual ~Camera();

	private:
		double heigh;
		double width;

		Vector eye;
		Vector target;
		Vector orientation;

};

#endif /* CAMERA_H_ */
