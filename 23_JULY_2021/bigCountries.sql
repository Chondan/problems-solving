select name, population, area
from World
where area > 3e6 or population > 25e6;

# Another approach which is faster
select name, population, area
from World
where area > 3e6
union
select name, population, area
from World
where population > 25e6;