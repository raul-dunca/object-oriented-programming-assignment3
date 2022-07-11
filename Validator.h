#pragma once
#include <string>
#include "Domain.h"

class ValidationException
{
private:
	std::string message;

public:
	ValidationException(std::string _message);
	std::string getMessage() const;
};


class CoatValidator
{
public:
	static void validate(const TrenchCoat& s);
};

