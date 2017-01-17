#include "UtilityNPC.h"
#include <iostream>

using namespace UtilitySystem;

void UtilityNPC::selectAction(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());
	m_foodValue.setValue(getFoodValue());
	m_restValue.setValue(getRestValue());
	m_logValue.setValue(getNumberOfLogs());
	float fBestScore = 0.0f;
	std::string strBestAction = "buildHouse";
	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}
	}
	if (strBestAction == "collectWater")
	{
		collectWater(a_fdeltaTime);
	}
	else if (strBestAction == "collectFood")
	{
		collectFood(a_fdeltaTime);
	}
	else if (strBestAction == "getSleep")
	{
		rest(a_fdeltaTime);
	}
	else if (strBestAction == "getLogs")
	{
		chopTree(a_fdeltaTime);
	}
	else if (strBestAction == "buildHouse")
	{
		buildHouse(a_fdeltaTime);
	}
}