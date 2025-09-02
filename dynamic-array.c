//#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int size;
    int* array;
} IntArray;

IntArray init()
{
    IntArray temp;
    temp.size = 0;
    temp.array = malloc(sizeof(int));
    return temp;
}

void print(IntArray* temp)
{
    for(int i = 0; i<temp->size; i++)
    {
        printf("%d: %d\n", i, temp->array[i]);
    }
}

void add(IntArray* temp, int data)
{
    temp->size += 1;
    temp->array =realloc(temp->array, sizeof(int) * temp->size);
    temp->array[temp->size-1] = data;
}

void replaceAtIndex(IntArray* temp, int index, int data)
{
    if(index >= temp->size || index < 1)
    {
        printf("Error: invalid index.\n");
        return;
    }
    temp->array[index] = data;
}

void deleteAtIndex(IntArray* temp, int index)
{
    temp->array[index] = 0;
}

int findNextIntIndex(IntArray* temp, int last_empty_index)
{
    int next_int_index = -1;

    for(int i = last_empty_index; i < temp->size; i++)
    {
        if(temp->array[i] != 0)
        {
            next_int_index = i;
            break;
        }
    }

    return next_int_index;
}

void resize(IntArray* temp)
{
    int last_empty_index = -1;
    int current_index;
    int zero_count = 0;

    for(int i = 0; i < temp->size; i++)
    {
        if(temp->array[i] == 0)
        {
            last_empty_index = i;
            int next_int_index = findNextIntIndex(temp, last_empty_index);
            replaceAtIndex(temp, last_empty_index, temp->array[next_int_index]);
            temp->array[next_int_index] = 0;
        }
    }
    for(int i = 0; i < temp->size; i++)
    {
        if(temp->array[i] == 0)
        {
            zero_count++;
        }
    }
    temp->size -= zero_count;
    temp->array =realloc(temp->array, sizeof(int) * temp->size);
}

void destroy(IntArray* temp)
{
    free(temp->array);
    temp->size = 0;
}

int main()
{
    IntArray Array = init();
    for(int i = 0; i<10; i++)
    {
        add(&Array, i+1);
    }

    print(&Array);
    printf("Size: %d\n", Array.size);

    deleteAtIndex(&Array, 8);
    deleteAtIndex(&Array, 3);
    resize(&Array);

    print(&Array);
    printf("Size: %d\n", Array.size);

    destroy(&Array);
    return 0;
}
