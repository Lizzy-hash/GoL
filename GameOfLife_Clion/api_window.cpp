#include "api_window.h"

void api_window::view()
{	
	static int dx = 10, dy = 10;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (tab[i * row + j]) ::Rectangle(m_hdc, i * dx, j * dx, i * dy, j * dy);
			else ::Ellipse(m_hdc, i * dx, j * dy, (i + 1) * dx, (j + 1) * dy);

		}

	}


}

void api_window::InitApi(HWND hwnd)
{
	m_hdc = GetDC(hwnd);
}

void api_window::play()
{
	while (2 > 1) {
		view();
		//Sleep(500);
		cycle_of_life();

	}
}
