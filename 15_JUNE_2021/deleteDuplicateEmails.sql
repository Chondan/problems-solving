# Write a SQL query to delete all duplicate email entries in 
# a table named Person, keeping only unique emails based on its smallest Id.

delete p1 from
Person p1
join
Person p2
on p1.Email = p2.Email
where
p1.Id > p2.Id;