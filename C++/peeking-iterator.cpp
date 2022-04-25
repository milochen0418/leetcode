/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */
//https://www.796t.com/article.php?id=233555 C++ 繼承用法
/*
//子類Son
class Son : public Base {
public:
	//子類Son呼叫父類的有參構造
	Son() :Base(1, 2, 3) {
		cout << "Son呼叫Base的有參構造" << endl;
	}
public:
	int m_D;
};
*/
//And I also refer this answer
//https://leetcode.com/problems/peeking-iterator/discuss/72554/Simple-C%2B%2B-solution-(1-line-per-method)-without-extra-member-variables

class PeekingIterator : public Iterator {
public:
    //https://leetcode.com/problems/peeking-iterator
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        return Iterator::next();	    
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};