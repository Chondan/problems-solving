select Name as Customers from

(select Name, CustomerId from Customer c
left join Orders o
on c.id = o.CustomerId) as temp

where temp.CustomerId is NULL;