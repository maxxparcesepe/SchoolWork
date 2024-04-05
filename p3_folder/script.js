let nums = [document.getElementById("num1"), document.getElementById("num2"), document.getElementById("num3")];
 
document.getElementById("cal").onclick = function calculateDisplay()
{
  let counter = 0;
  let min = nums[0];
  let max = nums[0];
  let median = 0;
  let range = 0;
  let mean = 0;

    
    for(i=0; i < nums.length; i++)\
    {
        
        if(parseInt(nums[i] < min)){
            
            min = parseInt(nums[i]);
        }
        
        if(parseInt((nums[i] > max ))){
            
            max = parseInt(nums[i]);
        }
        
        counter++; 
        
        let adder =+ parseInt(nums[i]);
    }
    
    median = parseInt(nums.length)/2;
    
    range = max - min;
    
    mean = adder/ counter;
    
    
    
    
document.getElementById("min").innerHTML = min;
document.getElementById("max").innerHTML = max;
document.getElementById("median").innerHTML = median;
document.getElementById("rng").innerHTML = range;
document.getElementById("avg").innerHTML = mean;
    
    
}