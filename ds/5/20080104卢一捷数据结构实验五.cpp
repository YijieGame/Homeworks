void Binary_Search(int a[], int low, int high, int search_num)    //low和high是端点区间
{
    int mid = (low + high) / 2;   //求中间值
    while(high >= low)            //大前提
    {
        if(a[mid] > search_num)
        {
            if(a[low] <= search_num)
            {
                Binary_Search(a, low, mid - 1,search_num);  //一个递归过程，将high变成原来mid的前一个
                return;
            }
            else
            {
                cout<<"数组中没有这个元素"<<endl;
                return;
            }
       }
       if(a[mid] == search_num)
       {
 	   cout<<"找到啦,该数为："<<a[mid]<<endl;
           return;
       }
       if(a[mid] < search_num)
       {
           if(a[high] >= search_num)
           {
               Binary_Search(a, mid + 1, high, search_num);    //同理
               return;
           }
           else
           {
                cout<<"数组中没有这个元素"<<endl;
                return;
           }
       }
   }
}