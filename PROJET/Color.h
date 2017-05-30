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
		Color(unsigned int red, unsigned int green, unsigned int blue);
		virtual ~Color();

		void setRed(unsigned int red);
		void setGreen(unsigned int green);
		void setBlue(unsigned int blue);

		unsigned int getRed() const;
		unsigned int getGreen() const;
		unsigned int getBlue() const;

		void print() const;

//		Color& operator*=(double l);
//		Color& operator/=(double l);
//		Color& operator+=(const Color& c);
//		Color& operator-=(const Color& c);



	private:
		unsigned int red;
		unsigned int green;
		unsigned int blue;

};

//Color operator*(double l, Color const& c);
//Color operator/(Color const& c, double l);
//Color operator+(Color const& c1, Color const& c2);
//Color operator-(Color const& c1, Color const& c2);


#endif /* COLOR_H_ */
