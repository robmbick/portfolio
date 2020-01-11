#pragma once

class Enemy
{
public:
	Enemy();
	Enemy(int x, int y);
	Enemy(Enemy const& obj);
	~Enemy();

	Enemy	&operator=(Enemy const& obj);

	void	set_coord(int x, int y);
	void	set_x(int x);
	void	set_y(int y);

	int		get_x() const;
	int		get_y() const;
	int		get_width() const;
	int		get_heights() const;
private:
	int _x;
	int _y;
	int _width;
	int _heights;
};
