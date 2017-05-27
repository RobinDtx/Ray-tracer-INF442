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

		double getKar() const;
		double getKag() const;
		double getKab() const;

		double getKdr() const;
		double getKdg() const;
		double getKdb() const;

		double getKsr() const;
		double getKsg() const;
		double getKsb() const;

		double getAlpha() const;

		void setKa(double ka);
		void setKd(double kd);
		void setKs(double ks);
		void setAlpha(double alpha);

	private:
		double kar; // composante ambiante
		double kag;
		double kab;

		double kdr; // composante diffuse
		double kdg;
		double kdb;

		double ksr; // composante spéculaire
		double ksg;
		double ksb;

		double alpha; // Brillance
};

#endif /* MATERIAU_H_ */
