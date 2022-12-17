#include "helpers.h"
#include "stdio.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{    
    for ( int i = 0; i < height; i++)
    {    
     for (int  j = 0; j < width; j++)
     {
       int n = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
       image[i][j].rgbtBlue = n;
       image[i][j].rgbtGreen = n; 
       image[i][j].rgbtRed = n;      
     } 
    }    
    return;

}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*  sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
  sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
  sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue*/
  for(int i = 0; i < height; i++) 
  {
    for ( int j = 0; j < width; j++)
    {
         
        int original_red = image[i][j].rgbtRed;
        int original_green = image[i][j].rgbtGreen;
        int original_blue = image[i][j].rgbtBlue;

        image[i][j].rgbtRed = round(.393 * original_red + .769 * original_green + .189 *   original_blue);
        image[i][j].rgbtGreen = round(.349  * original_red  + .686  *  original_green + .168 * original_blue);
        image[i][j].rgbtBlue = round(.272  *   original_red + .534 *  original_green + .131 *   original_blue);
        
        if(round(.393 * original_red + .769 * original_green + .189 *   original_blue) > 255) 
        {
            image[i][j].rgbtRed = 255;
        }
        if (round(.349  * original_red  + .686  *  original_green + .168 * original_blue) > 255) 
        {
            image[i][j].rgbtGreen = 255;
        }
        if (round(.272  *   original_red + .534 *  original_green + .131 *   original_blue) > 255) 
        {
            image[i][j].rgbtBlue = 255;
        }
    }
    

  }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{ 
    for (int i = 0; i < height; i++) 
    {
        
         int n = width - 1; //last pixel in the row 
        for (int j = 0; j < width/2; j++, n--) 
        {
            /* for each row 
               swap the pixels horizontally opposite sides
               how to achieve this?
               solution 1 : 
               Copy the  first half of the pixels in an array left 
               Copy the second half of the pixels in an array right 
               copy right into the first half of the array 
               copy left into the second half of the array

               solution 2 : 

              for loop (i < heigth )
                int n = width/2;
                for loop (j < width/2, j++ n++) 
                    image[i][j] = image[i][n]      
            */
           
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][n];
            image[i][n] = tmp;
            
            /*The problem is that on line 86, it is copying n that its value is the half of the width, so i'm copying the half of the image pixel into image[i][j]
            what's the desired result
            it is to copy the last NOT THE Half of the pixels into image[i][j]
            in order to do that 

            n = width -1  
            for(j < width/2 j++, n--)*/

        }
    }
    return;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{       

     RGBTRIPLE copy[height][width]; 
     for (int k = 0; k < height; k++ ) 
     {
     for(int l = 0; l < width; l++) 
     {
         copy[k][l] = image[k][l];
     }    
     }
          
 for (int i = 0; i < height; i++) 
    {
     
        for(int j = 0; j < width; j++) 
        {
            /*How can I create a standarized way of going throught the values that I want average that will be less likely to errors
            GR
            for (int n = i-1  n < i+1  ) 
            {
                new color += copy[n][j] 
            }
            */
            float red = 0;
            float green = 0;
            float blue = 0;
            int  counter = 0;
            /* why the code doesn't  work 
            the loop it's going from i - 1, j -1 to i +1 , j +1;
            so if I print the value of counter it will be 4 
            the grid is formed by 9 pixels not 4, 
            what are the values missing?
            the values i'm getting :
            copy[i-1][j-1], copy[i][j], copy[i+1][j+1] copy[i+2][j+2]
            the first mistake is that i + 2 j +2  is not part of the grid 
            second : copy[i][j-1] copy[i][j+1] copy[i+1][j-1] copy[i+1][j-1]
            copy[i-1][j] copy[i-1][j+1]
            how do I make my solution in such a way that takes in account these missing values?
            solution 1 :
            loop [i][j] 
            
            */
           //from j -1 to j +1  
            for(int c = j - 1; c < j ; c++) 
            {
                red += copy[i][c].rgbtRed;
                green += copy[i][c].rgbtGreen;
                blue += copy[i][c].rgbtBlue;
            }
            //from i - 1 to i  +1
            for(int r =  i - 1; r < i; r++) 
            {
               red += copy[r][j]
            }

            /*
            int red  = round((copy[i][j+1].rgbtRed + copy[i][j-1].rgbtRed + copy[i][j].rgbtRed +
            copy[i + 1][j].rgbtRed + copy[i + 1][j+1].rgbtRed + copy[i + 1][j-1].rgbtRed +
            copy[i-1][j].rgbtRed + copy[i - 1][j+1].rgbtRed + copy[i - 1][j-1].rgbtRed)/9.0);

            int green  = round((copy[i][j+1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen +
            copy[i + 1][j].rgbtGreen + copy[i + 1][j+1].rgbtGreen + copy[i + 1][j-1].rgbtGreen +
            copy[i-1][j].rgbtGreen + copy[i - 1][j+1].rgbtGreen + copy[i - 1][j-1].rgbtGreen)/9.0);
        
            int blue = round((copy[i][j+1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue +
            copy[i + 1][j].rgbtBlue + copy[i + 1][j+1].rgbtBlue + copy[i + 1][j-1].rgbtBlue +
            copy[i-1][j].rgbtBlue + copy[i - 1][j+1].rgbtBlue + copy[i - 1][j-1].rgbtBlue)/9.0);
*/            
                if(red > 255) 
                {
                    red = 255;
                }
                if(blue > 255) 
                {
                    blue = 255;
                }
                if(green > 255 ) 
                {
                    green = 255;
                }
 
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
}
   
}
}

