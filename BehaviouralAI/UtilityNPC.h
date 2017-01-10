#ifndef UTILITYNPC_H_
#define UTILITYNPC_H_

#include "src\BaseNPC.h"
#include "src\UtilityValue.h"
#include "src\UtilityScore.h"
#include <map>

namespace UtilitySystem
{
	class UtilityNPC : public BaseNPC
	{
	public:
		UtilityNPC(World* pWorld);
		~UtilityNPC();
	protected:
		void selectAction(float a_fdeltaTime) override;
	private:
		UtilityValue m_waterValue;
		std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
	};
}
#endif