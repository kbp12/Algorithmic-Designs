select stock_name, sum(if(operation = 'Sell',1,-1)*price) as capital_gain_loss
from Stocks
group by stock_name;