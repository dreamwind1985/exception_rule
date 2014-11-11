#include <hastmap>

static unsigned int sg_max_hash_size = 49152;

namespace firewall
{
	class ExcludeRule;
	class ExcludeRuleCtrl
	{
		public:
			ExcludeRuleCtrl():m_exclude_rule_hash(sg_max_hash_size){};
			~ExcludeRuleCtrl()
			{
				Clear();
			}
			void Clear();
			bool Parse(const std::string & fname);
			bool RuleIsExclude(unsigned int ruleid, const Packet &p);
		private:
			void AddExcludeRuleObj(ExcludeRule * obj);
			bool RuleIsRedundant(ExcludeRule * obj);
			ExcludeRuleCtrl & operator=(const ExcludeRuleCtrl &Value){};
			ExcludeRuleCtrl( const ExcludeRuleCtrl & exclude_rule_ctrl_obj){};

		private:
			std::hash_multimap< unsigned int, ExcludeRule* > m_exclude_rule_hash;

	}
}
