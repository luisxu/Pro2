/**
 * @file Appointment.cpp
 * @brief Appointment implementation
 */

#include "Appointment.hpp"

Appointment::Appointment(int app_day, int id_offi, int app_hour, int id_app)
{
    this->app_day = app_day;
    this->id_offi = id_offi;
    this->app_hour = app_hour;
    this->id_app = id_app;
}

Appointment::~Appointment()
{}

int Appointment::consult_app_day() const
{
	return app_day;
}

void Appointment::write_app() const
{
	cout << app_day << " " << id_offi << " " << app_hour << " " << id_app << endl;
}

