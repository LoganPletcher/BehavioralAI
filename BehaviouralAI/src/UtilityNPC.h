#ifndef UTILITYNPC_H_
#define UTILITYNPC_H_

#include "BaseNPC.h"
#include "UtilityValue.h"
#include "UtilityScore.h"
#include <map>

using namespace UtilitySystem;

class UtilityNPC : public BaseNPC
{
public:
	UtilityNPC(World* pWorld) : BaseNPC(pWorld)
	{
		m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_waterValue.setMinMaxValues(0, 15);
		m_waterValue.setValue(getWaterValue());
		UtilityScore* pWaterScore = new UtilityScore();
		pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
		m_pUtilityScoreMap["collectWater"] = pWaterScore;
		m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_foodValue.setMinMaxValues(0, 20);
		m_foodValue.setValue(getFoodValue());
		UtilityScore* pFoodScore = new UtilityScore();
		pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
		m_pUtilityScoreMap["collectFood"] = pFoodScore;
		m_restValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_restValue.setMinMaxValues(0, 17);
		m_restValue.setValue(getRestValue());
		UtilityScore* pRestScore = new UtilityScore();
		pRestScore->addUtilityValue(&m_restValue, 1.0f);
		m_pUtilityScoreMap["getSleep"] = pRestScore;
		m_logValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
		m_logValue.setMinMaxValues(0, 1);
		m_logValue.setValue(getNumberOfLogs());
		UtilityScore* pLogScore = new UtilityScore();
		pLogScore->addUtilityValue(&m_logValue, 1.0f);
		m_pUtilityScoreMap["getLogs"] = pLogScore;
	}
	~UtilityNPC();
protected:
	void selectAction(float a_fdeltaTime) override;
private:
	UtilityValue m_waterValue;
	UtilityValue m_foodValue;
	UtilityValue m_restValue;
	UtilityValue m_logValue;
	std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
};
#endif