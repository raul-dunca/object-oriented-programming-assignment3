#include "Validator.h"

using namespace std;

ValidationException::ValidationException(std::string _message) : message{ _message }
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}



void CoatValidator::validate(const TrenchCoat& s)
{
	string errors;
	if (!(s.getSize().size() < 4 and s.getSize().size() > 0))
		errors += string("\nError the Coat size needs to be between 1 and 3 characters\n");

	if (!(s.getColour().size() < 10 and s.getColour().size() > 2))
		errors += string("\nError the Coat colour needs to be between 3 and 10 characters\n");

	if (!(s.getPrice() < 1000 and s.getPrice() > 0))
		errors += string("\nError the Coat price needs to be less than 1000\n");
	if (!(s.getQuantity() <= 1000))
		errors += string("\nError the Coat quantit needs to be less than 1000\n");


	if (errors.size() > 0)
		throw ValidationException(errors);

	/*if (errors.size() > 0)
		throw ValidationExceptionInherited(errors);*/
}
