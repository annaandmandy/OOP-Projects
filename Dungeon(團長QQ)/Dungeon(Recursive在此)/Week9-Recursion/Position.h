#pragma once
struct Position {
	Position() {
		x = 0;
		y = 0;
	}
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x; // X, y Coordinate
	int y;
};