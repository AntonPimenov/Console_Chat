#pragma once
#include "User.h"

template <typename T> class UserArray
{
public:
	//дефолтный конструктор
	UserArray() = default;

	//коструктор по количеству пользователей в массиве
	UserArray(int size) : users_count_(size)
	{
		users_ = new T[size]{};
	}

	//деструктор
	~UserArray()
	{
		delete[] users_;
	}

	//конструктор копирования
	UserArray(const UserArray& UserArray)
	{
		reallocate(UserArray.getLength());

		for (int i = 0; i < users_count_; ++i)
			users_[i] = UserArray.users_[i];
	}

	//функция изменения количества пользователей в массиве
	void reallocate(int new_size)
	{
		erase();

		if (new_size <= 0)
			return;

		users_ = new T[new_size];
		users_count_ = new_size;
	}

	//функция очистки массива пользователей
	void erase()
	{
		delete[] users_;
		users_ = nullptr;
		users_count_ = 0;
	}

	T& operator[](int i)
	{
		if (i >= 0 and i <= users_count_)
			return users_[i];
		
	}

	
	//функция отражения информации по всем пользователям в массве
	void print()
	{
		if (users_)
		{
			for (int i = 0; i < users_count_; i++)
			{
				users_[i]->printUser();
			}
		}
	}

	//функция добавления пользователя в массив
	void add(T user)
	{
		T* new_users_ = new T[users_count_ + 1];
		for (int i = 0; i < users_count_; i++)
		{
			new_users_[i] = users_[i];
		}
		new_users_[users_count_] = user;
		delete[] users_;
		users_ = new_users_;
		++users_count_;
	}

	//функция удаления пользователя из массива
	void remove(T user)
	{
		for (int i = 0; i < users_count_; i++)
		{
			if (users_[i] == user)
			{
				users_[i] = users_[i + 1];
				users_count_--;
			}
		}
	}

	//функция получения класса пользователя из массива по его имени
	User* getUserByName(string Name)
	{
		for (int i = 0; i < users_count_; i++)
		{
			if (users_[i]->username_ == Name) return users_[i];
		}
		return 0;
	}

	// геттер количества пользователей в массиве
	int getLength()
	{
		return users_count_;
	}
private:
	T* users_; // ссылка на массив
	int users_count_; // счётчик пользователей в массиве
};
