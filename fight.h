#pragma once

#include "witcher.h"
#include "enemy.h"

class Fight
{

public:
	Fight();
	virtual void start() const;
	virtual ~Fight() = default;	
};


// 3 derived classes