#ifndef SWAPPER_H
#define SWAPPER_H

#include "tree.h"
#include "random.h"

class Swapper {

	public:
		Swapper();

		/*	Check whether the node is appropriate for this type of
		 *	substitution.
		 */
		virtual bool canSwap(Node* node)=0;

		/*	Perform the substitution on the node.
		 */
		virtual void swap(Node* node)=0;

		/*	Whether this swapper can be used. If false, then canSwap must
		 *	always return false.
		 *	By default, 'enabled' is false.
		 */
		void setEnabled(bool b);

	protected:
		void replace(Node* node, Node* other);
		Random random;
		bool enabled;
};

#endif	//	SWAPPER_H
