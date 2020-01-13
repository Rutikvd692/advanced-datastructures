import java.util.Scanner;

class Heap{
		public static int a[]=new int[50];
		public static int n,i;
		
		public static void read()
		{
			Scanner s=new Scanner(System.in);
			System.out.println("\nEnter the size of array:");
			n=s.nextInt();
			System.out.println("\nEnter the elements of array:");
			for(i=0;i<n;i++)
			{
				a[i]=s.nextInt();
			}
		}

		public static void display()
		{
			System.out.println("\nThe elements of array are:");
			for(i=0;i<n;i++)
			{
				System.out.println(+a[i]);
			}
		
		}
		
		public static void reheap_down(int i)
		{
			int l,r,x,t;
			while(2*i+1<n)
			{
				l=2*i+1;
				r=2*i+2;
		
				if(a[l]<a[r]&&(r<=n))
				{
					x=r;
				}
				else
				{
					x=l;
				}
		
				if(a[i]<a[x])
				{
					t=a[i];
					a[i]=a[x];
					a[x]=t;
				}
				else
				{
					break;
				}
				i=x;		
			}
		}

		public static void  heap_sort()
		{
			int n1,temp;
			for(int i=(n-1)/2; i>=0;i--)
			{
				reheap_down(i);
				display();
			}
			n1=n;
			n--;
			while(n>=0)
			{
				temp=a[0];
			a[0]=a[n];
			a[n]=temp;
			n--;
			reheap_down(0);
			display();
			}
       			n=n1;
		}
		
		public static void shellsort()
		{
		    for (int gap = n / 2; gap > 0; gap /= 2) 
		    { 
			    for (int i = gap; i < n; i += 1) 
		        {
		            int temp = a[i]; 
				    int j; 
				    for (j = i; j >= gap && a[j - gap] > temp; j -= gap) 
				    {
					    a[j] = a[j - gap]; 
				    }
				    a[j] = temp; 
			    } 
		    } 
 
	    } 
		    
		public static void main(String args[])
		{
			
			read();
			display();
			heap_sort();
			display();
			shellsort();
			display();
		}		
}
