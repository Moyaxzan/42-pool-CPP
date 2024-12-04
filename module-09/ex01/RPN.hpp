#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
class RPN {
	public:
		// CANONICAL FORM
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN(void);

		// PUBLIC MEMBER FUNCTIONS
		void makeOperation(char c);
		int getResult(void) const;

	private:
		// ATTRIBUTES
		std::stack<int> stack_;

		// PRIVATE MEMBER FUNCTIONS
		void applyAdd_(void);
		void applySubstract_(void);
		void applyMult_(void);
		void applyDivide_(void);
		int getOperationNum_(char c) const;
		int betterPop_(void);
};

#endif
