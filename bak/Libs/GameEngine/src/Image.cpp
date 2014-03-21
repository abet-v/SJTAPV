#include "Image.hh"

Image::Image(std::string fileName)
{
	char		*new_data;
	char		tmp_px[4];
	int		 	cnt;
	int		  x;
	int		  y;

	this->data_ = (char*)stbi_load((char*)fileName.c_str(),
		&this->width_, &this->height_,
		&this->bitdepth_, 4);
	std::cout << (this->data_ ? "Not Null" : "Null") << " Width : " << this->width_ <<
	" Height : " << this->height_ << " N : " << this->bitdepth_ << std::endl;

	if (this->data_)
	{
		new_data = (char*)malloc(this->bitdepth_ * (this->width_ * this->height_));

		cnt = 0;
		y = 0;
		while (y < this->height_)
		{
			x = 0;
			while (x < this->width_)
			{
				new_data[cnt * 4 + 0] = this->data_[cnt * 4 + 2];
				new_data[cnt * 4 + 1] = this->data_[cnt * 4 + 1];
				new_data[cnt * 4 + 2] = this->data_[cnt * 4 + 0];
				new_data[cnt * 4 + 3] = this->data_[cnt * 4 + 3];
				cnt++;
				x++;
			}
			y++;
		}
		stbi_image_free(this->data_);
		this->data_ = new_data;
	}
}

int		Image::getHeight()
{
	return (this->height_);
}

int		Image::getWidth()
{
	return (this->width_);
}

int		*Image::getData()
{
	return ((int*)this->data_);
}
