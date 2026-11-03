/*
 * fahrrad.h
 *
 *  Created on: 01.11.2026
 *      Author: n3034770
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include <vector>
#include <string>

class Fahrrad{
private:
	const size_t _id;
	static size_t _next_id;
	static size_t _rented_count;
	std::string _model;
	int _km;
	bool _rent;
	int _last_service;
public:
	Fahrrad(std::string model, int km = 0);
	~Fahrrad();
	//getter
	size_t get_id() const;
	const std::string& get_model() const;
	int get_km() const;
	bool get_rent_status() const;
	//setter
	bool set_rent(); // set rent true
	bool give_back(int km); // set rent false
	bool wartung_noetig(int grenze = 500) const;
	bool wartung();
	friend void umbau(Fahrrad& a, Fahrrad& b);
	Fahrrad(const Fahrrad&) = delete;
	Fahrrad& operator=(const Fahrrad&) = delete;
	static size_t& get_cnt();

};

void umbau(Fahrrad& a, Fahrrad& b);
// wenn in werkstatt und verschieden - swap



#endif /* FAHRRAD_H_ */
