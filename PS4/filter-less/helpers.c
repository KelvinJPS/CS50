#include "helpers.h"
#include "stdio.h"
#include "math.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{    
    for (int i = 0; i < height; i++)
    {    
        for (int  j = 0; j < width; j++)
        {
            int n = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
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
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++)
        {
         
            int original_red = image[i][j].rgbtRed;
            int original_green = image[i][j].rgbtGreen;
            int original_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = round(.393 * original_red + .769 * original_green + .189 *   original_blue);
            image[i][j].rgbtGreen = round(.349  * original_red  + .686  *  original_green + .168 * original_blue);
            image[i][j].rgbtBlue = round(.272  *   original_red + .534 *  original_green + .131 *   original_blue);
        
            if (round(.393 * original_red + .769 * original_green + .189 *   original_blue) > 255) 
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
        for (int j = 0; j < width / 2; j++, n--) 
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
    for (int i = 0; i < height; i++) 
    {
        for (int j = 0; j < width; j++) 
        {
            copy[i][j] = image[i][j];
        }    
    }
          
    for (int i = 0; i < height; i++) 
    {
     
        for (int j = 0; j < width; j++) 
        {
            int red = 0;
            int green = 0;
            int blue = 0;
            float pixels = 9;
            float counter = 0;     
        
            for (int k = -1; k < 2; k++) 
            
            {
                for (int l = -1; l < 2; l++) 
                {
                    if ((i + k) >= 0 && (j + l) >= 0 && (i + k) <= height - 1 && (j + l) <= width - 1) 
                    {
                        counter++;
                        red += copy[i + k][j + l].rgbtRed;
                        green += copy[i + k][j + l].rgbtGreen;
                        blue += copy[i + k][j + l].rgbtBlue;
                    }
                } 
                 
            }
            red = round(red / counter);
            blue = round(blue / counter);
            green = round(green / counter);         
             
            if (red > 255) 
            {
                red = 255;
            }
            if (blue > 255) 
            {
                blue = 255;
            }
            if (green > 255) 
            {
                green = 255;
            }
 
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
   
    }
}

