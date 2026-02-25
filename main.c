#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
	item_list[index].price = price;
	
	//add 1, bcs strlen() doesnt count the null terminator
	item_list[index].sku = (char *)malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);
	
	item_list[index].category = (char *)malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);
	
	item_list[index].name = (char *)malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size){
	for(int i = 0; i < size; i++){
		free(item_list[i].sku);
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list);
}

double average_price(Item *item_list, int size){
	double total = 0.0;
	for(int i = 0; i < size; i++){
		total += item_list[i].price;
	}
	return total/size;
}

void print_items(Item *item_list, int size){
	for(int i = 0; i < size; i++){
		printf("############### \n");
		printf("Item's name: %s\n", item_list[i].name);
		printf("Item's sku: %s\n", item_list[i].sku);
		printf("Item's category: %s\n", item_list[i].category);
		printf("Item's price: %f\n", item_list[i].price);		
	}
	printf("############### \n");
}

int main(int argc, char *argv[]){
	int size = 5;
	//allocate space for 5items
	Item *item_list = (Item *)malloc(size * sizeof(Item));
	
	add_item(item_list, 1.23, "78234", "Produce", "Bananas", 0);
	add_item(item_list, 3.60, "56743", "Pantry", "Thailand Rice", 1);
	add_item(item_list, 8.20, "13575", "Meat", "Pork", 2);
	add_item(item_list, 2.50, "89245", "Beverage", "Root Beer", 3);
	add_item(item_list, 6.25, "45088", "Bakery", "Cookies", 4);
	
	print_items(item_list, size);
	
	double avg = average_price(item_list, size);
	printf("Average price of items = %f\n", avg);
	
	if(argc > 1){
		char *search_sku = argv[1];
		int ct = 0;
		
		while(ct < size && strcmp(item_list[ct].sku, search_sku) != 0){
			ct++;
		}
		
		if(ct < size){
			printf("\nItem found: \n");
			printf("Item's name: %s\n", item_list[ct].name);
			printf("Item's sku: %s\n", item_list[ct].sku);
			printf("Item's category: %s\n", item_list[ct].category);
			printf("Item's price: %f\n", item_list[ct].price);
		}
		
		else{
			printf("\nItem not found!");
		}
	}
	
	free_items(item_list, size); //free memory
	
	return 0;
}