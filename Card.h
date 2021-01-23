#ifndef CARD_H
#define CARD_H
#include <string>
#include <stdexcept>
namespace TarotReader{
    class Card{
    	std::string cardName;
    	std::string upAttributes[5];
    	std::string revAttributes[5];

    public:
    	std::string getCardName();
    	std::string getUpAttr();
    	std::string getrevAttr();
    
    };

    std::string Card::getCardName(){
	    return cardName;
    }

    std::string Card::getUpAttr(){
    
    	// Concatenates all upright attributes into a single string for output purposes.
    	std::string allAttr;
    	
    	for (int i = 0; i < 5; i++){
	    	try{
		    	allAttr = allAttr + upAttributes[i];
	    	}
		    // If there's less than 5 attributes, we skip over it.
	    	// Shane 20200123:
	    	// If we do not have any more we can break out of it altogether
		    catch (const std::out_of_range& oor) {
		    	break;
	    	}
		
    	}

	    return allAttr;
    }

    std::string Card::getrevAttr(){

	    // Concatenates all reversed attributes into a single string for output purposes.
	    std::string allAttr;

	    for (int i = 0; i < 5; i++){
	    	try{
	    		allAttr = allAttr + revAttributes[i];
	    	}
		// If there's less than 5 attributes, we skip over it.
		// Shane 20200123:
		// If we do not have any more we can break out of it altogether
		    catch (const std::out_of_range& oor){
	    		break;
	    	}

    	}
    
	    return allAttr;
    }
}

#endif
