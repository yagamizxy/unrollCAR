#include "MainSolver.h"

namespace car
{
    MainSolver::MainSolver(std::shared_ptr<AigerModel> model, bool isForward, bool extractMUC)
    {
        m_isForward = isForward;
        m_extractMUC = extractMUC;
        m_model = model;
        m_maxFlag = model->GetMaxId()+1;
		auto& clause = m_model->GetClause();
		for (int i = 0; i < clause.size(); ++i)
		{
			AddClause(clause[i]);
		}
    }

}//namespace car