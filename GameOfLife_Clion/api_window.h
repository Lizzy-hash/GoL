#pragma once
#ifndef _API_WINDOW_
#define _API_WINDOW_


#pragma once

#include "engine.h"

class api_window : public engine{

public:
	api_window(unsigned row, unsigned col) : engine(row, col) {};

	void view();

	void InitApi(HWND hwnd);

	void play();
	virtual ~api_window() {};

private:
	HDC m_hdc;
};

#endif //!_API_WINDOW_