/*
 * Materiau.h
 *
 *  Created on: 25 mai 2017
 *      Author: egoutierre
 */

#ifndef MATERIAU_H_
#define MATERIAU_H_

class Materiau {
	public:
		Materiau();
		Materiau(double ka, double kd, double ks, double alpha);
		virtual ~Materiau();

		double getKa() const;
		double getKd() const;
		double getKs() const;
		double getAlpha() const;

		void setKa(double ka);
		void setKd(double kd);
		void setKs(double ks);
		void setAlpha(double alpha);

	private:
		double ka; // composante ambiante
		double kd; // composante diffuse
		double ks; // composante spéculaire
		double alpha; // Brillance
};

#endif /* MATERIAU_H_ */
