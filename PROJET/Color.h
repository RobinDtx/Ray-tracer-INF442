/*
 * Color.h
 *
 *  Created on: 16 mai 2017
 *      Author: egoutierre
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color {
	public:
		Color();
		Color(int red, int green, int blue);
		virtual ~Color();

		void setRed(int red);
		void setGreen(int green);
		void setBlue(int blue);

		int getRed();
		int getGreen();
		int getBlue();


	private:
		int red;
		int green;
		int blue;

};

#endif /* COLOR_H_ */
