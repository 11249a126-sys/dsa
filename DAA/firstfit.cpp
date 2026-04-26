#include <stdio.h>

void firstFit(int items[], int n, int capacity)
{
    int bin[n]; // Remaining capacity of bins
    int binCount = 0; // Number of bins used

    printf("\nExecuting First Fit Algorithm\n");
    
    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
        bin[i] = 0;

    // Process each item
    for (int i = 0; i < n; i++)
    {
        //Item size exceeds capacity (capacity of all bins), 
        //cannot be placed in any bin as we should not split items and we have only one type of bin.
        if(items[i] > capacity) {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue; // Skip this item as it cannot be placed, continue to next item.
        }
        
        int placed = 0; //flag to check if item is placed

        // Check existing bins
        for (int j = 0; j < binCount; j++)
        {
            if (bin[j] >= items[i])
            {
                bin[j] -= items[i]; // Reduce remaining capacity
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break; // First Fit: stop at first match
            }
        }

        // Create new bin if not placed (means existing bins can't accommodate the item)
        if (!placed)
        {
            bin[binCount] = capacity; // Initialize new bin with full capacity
            bin[binCount] -= items[i];
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;
        }
    }

    printf("Total bins used = %d\n", binCount);
}


int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    /* Define an array to hold item sizes 
    1. Only after we know the number of items or 
    2. Define a large array and waste memory or 
    3. Use dynamic allocation 
    if this is not taken care then random values will be in the array */
    int items[n];

    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &capacity); // FIXED: %d instead of %f

    firstFit(items, n, capacity);

    return 0;
}

