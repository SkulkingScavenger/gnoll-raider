#ifndef DYNAMIC_ARRAY_SPRITE_H_
#define DYNAMIC_ARRAY_SPRITE_H_

class dynamic_array_spriteptr {
public:
	size_t length;
	size_t element_size = sizeof(Sprite*);
	void* begin;
	dynamic_array_spriteptr(unsigned int s){
		length = s;
		begin = malloc(s*element_size);
	}

	/** Destructor*/
	~dynamic_array_spriteptr(){
		free(begin);
	}

	/** Copy Constructor*/
	dynamic_array_spriteptr(const dynamic_array_spriteptr& other){
		length = other.length;
		begin = malloc(length*element_size);
		memcpy(begin, other.begin, length*element_size);
	}

	/** Copy Assignment Operator*/
	dynamic_array_spriteptr& operator=(const dynamic_array_spriteptr& other){
		length = other.length;
		begin = malloc(length*element_size);
		memcpy(begin, other.begin, length*element_size);
	}

	Sprite* get_element(unsigned int x){
		if (x < length){
			void* temp;
			memcpy(temp, &begin + (element_size*x), element_size);
			return static_cast<Sprite*>(temp);
		}
		else{
			return nullptr;
		}
	}

	void insert_element_at(unsigned int x, Sprite* spr){
		memcpy(&begin + (element_size*x), &spr, element_size);
	}

	/** Accessor Overload */
	Sprite* operator[](unsigned int x) const {
		if (x < length){
			void* temp;
			memcpy(temp, &begin + (element_size*x), element_size);
			return static_cast<Sprite*>(temp);
		}
		else{
			return nullptr;
		}
	}

	Sprite* & operator[](unsigned int x){
		Sprite* temp = get_element(x);
		return temp;
	}


};

#endif