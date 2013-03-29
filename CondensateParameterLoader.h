#ifndef CONDENSATEPARAMETERLOADER_H
#define CONDENSATEPARAMETERLOADER_H

#include "CondensationParameters.h"
#include <QString>

class CondensateParameterLoader{

public:
	CondensateParameterLoader();

	virtual CondensationParameters load(const QString& filename);
	virtual void save(const CondensationParameters& parameters, const QString& filename);
};

#endif // CONDENSATEPARAMETERLOADER_H
