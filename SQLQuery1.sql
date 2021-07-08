

/*AddUser*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddUser]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddUser]
END
GO
CREATE PROCEDURE dbo.usp_AddUser(
	@vusername VARCHAR(100),
	@vpassword VARCHAR(100),
	@vfirst_name VARCHAR(100),
	@vlast_name VARCHAR(100),
	@cgender CHAR(1),
	@vdocument_number VARCHAR(15),
	@vphone_number VARCHAR(50),
	@vaddress VARCHAR(150),
	@vemail VARCHAR(150),	
	@vcategory VARCHAR(15),
	@iid INT OUT
 ) AS 
	BEGIN
		INSERT INTO APP_USER (username, password, first_name, last_name, gender, 
								document_number, phone_number, address, email, category)
		SELECT 	@vusername, @vpassword, @vfirst_name, @vlast_name, @cgender, 
				@vdocument_number, @vphone_number, @vaddress, @vemail, @vcategory

		SET @iid = SCOPE_IDENTITY()	
	END
GO

/*QueryUserById*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryUserById]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryUserById]
END
GO
CREATE PROCEDURE dbo.usp_QueryUserById (
	@id INT
)
AS
	SELECT U.id as id, AU.username as username, AU.first_name as first_name, AU.last_name as last_name, AU.gender as gender, AU.email as email, 
			AU.document_number as document_number, AU.address as address, AU.phone_number as phone_number, 
			AU.email as email
	FROM APP_USER U
	INNER JOIN APP_USER AU ON U.id=AU.id 
	WHERE U.id=@id
GO

/*AddCustomer*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddCustomer]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddCustomer]
END
GO
CREATE PROCEDURE dbo.usp_AddCustomer(
	@username VARCHAR(100),
	@password VARCHAR(100),
	@first_name VARCHAR(100),
	@last_name VARCHAR(100),
	@gender CHAR(1),
	@document_number VARCHAR(15),
	@phone_number VARCHAR(50),
	@address VARCHAR(150),
	@email VARCHAR(150),
	@category VARCHAR(15),
    @customer_points INT,	
	@id INT OUT
) AS
	BEGIN
		EXEC dbo.usp_AddUser @vusername=@username, @vpassword=@password, @vfirst_name=@first_name, @vlast_name=@last_name, @cgender=@gender,
			@vdocument_number=@document_number, @vphone_number=@phone_number, @vaddress=@address, @vemail=@email, @vcategory=@category, @iid=@id OUTPUT 

		INSERT INTO CUSTOMER(id, customer_points)
		SELECT @id, @customer_points		
	END
GO

/*QueryCustomerById*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryCustomerById]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryCustomerById]
END
GO
CREATE PROCEDURE dbo.usp_QueryCustomerById (
	@id INT
)
AS
	SELECT C.id as id, AU.username as username, AU.first_name as first_name, AU.last_name as last_name, AU.gender as gender, AU.email as email, 
			AU.document_number as document_number, AU.address as address, AU.phone_number as phone_number, C.customer_points as customer_points
	FROM CUSTOMER C
	INNER JOIN APP_USER AU ON C.id=AU.id 
	WHERE C.id=@id
GO

/*AddManager*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddManager]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddManager]
END
GO
CREATE PROCEDURE dbo.usp_AddManager(
	@username VARCHAR(100),
	@password VARCHAR(100),
	@first_name VARCHAR(100),
	@last_name VARCHAR(100),
	@gender CHAR(1),
	@document_number VARCHAR(15),
	@phone_number VARCHAR(50),
	@address VARCHAR(150),
	@email VARCHAR(150),
	@category VARCHAR(15),
    @employees_number INT,	
	@id INT OUT
) AS
	BEGIN
		EXEC dbo.usp_AddUser @vusername=@username, @vpassword=@password, @vfirst_name=@first_name, @vlast_name=@last_name, @cgender=@gender,
			@vdocument_number=@document_number, @vphone_number=@phone_number, @vaddress=@address, @vemail=@email, @vcategory=@category, @iid=@id OUTPUT 

		INSERT INTO MANAGER(id, employees_number)
		SELECT @id, @employees_number		
	END
GO

/*AddDeliveryMan*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddDeliveryMan]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddDeliveryMan]
END
GO
CREATE PROCEDURE dbo.usp_AddDeliveryMan(
	@username VARCHAR(100),
	@password VARCHAR(100),
	@first_name VARCHAR(100),
	@last_name VARCHAR(100),
	@gender CHAR(1),
	@document_number VARCHAR(15),
	@phone_number VARCHAR(50),
	@address VARCHAR(150),
	@email VARCHAR(150),
	@category VARCHAR(15),
	@deliveryManRatingAverage DECIMAL(1, 1),
	@id INT OUT
) AS
	BEGIN
		EXEC dbo.usp_AddUser @vusername=@username, @vpassword=@password, @vfirst_name=@first_name, @vlast_name=@last_name, @cgender=@gender,
			@vdocument_number=@document_number, @vphone_number=@phone_number, @vaddress=@address, @vemail=@email, @vcategory=@category, @iid=@id OUTPUT 

		INSERT INTO DELIVERYMAN(id, deliveryManRatingAverage)
		SELECT @id, @deliveryManRatingAverage		
	END
GO

/*QueryDeliveryManById*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryDeliveryManById]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryDeliveryManById]
END
GO
CREATE PROCEDURE dbo.usp_QueryDeliveryManById (
	@id INT
)
AS
	SELECT C.id as id, AU.username as username, AU.first_name as first_name, AU.last_name as last_name, AU.gender as gender, AU.email as email, 
			AU.document_number as document_number, AU.address as address, AU.phone_number as phone_number, C.deliveryManRatingAverage as deliveryManRatingAverage
			
	FROM DELIVERYMAN C
	INNER JOIN APP_USER AU ON C.id=AU.id 
	WHERE C.id=@id
GO


/*AddGroceries*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddGroceries]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddGroceries]
END
GO
CREATE PROCEDURE dbo.usp_AddGroceries(
	@name VARCHAR(250),
	@description VARCHAR(500),
	@price DECIMAL(10,2),
	@stocktotal INT,
	@brand VARCHAR(50),
	@quantitySold INT,  
	@photo IMAGE,
	@id INT OUT
 ) AS 
	BEGIN
		INSERT INTO PRODUCT(name, description, price, stocktotal, status, photo, brand, quantitySold)
		SELECT @name, @description, @price, @stocktotal, 'A', @photo, @brand, @quantitySold
		SET @id = SCOPE_IDENTITY()	
	
		INSERT INTO GROCERY_PRODUCT(id)
		SELECT @id
	END
GO
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_UpdateGroceries]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_UpdateGroceries]
END
GO
CREATE PROCEDURE dbo.usp_UpdateGroceries(
	@name VARCHAR(250),
	@description VARCHAR(500),
	@price DECIMAL(10,2),
	@stocktotal INT,
	@status CHAR(1),
	@brand VARCHAR(50),
	@quantitySold INT,
	@photo IMAGE,
	@id INT
 ) AS 
	BEGIN
		UPDATE PRODUCT
		SET name=@name, description=@description, price=@price, stocktotal=@stocktotal, status=@status, brand=@brand, quantitySold=@quantitySold, photo=@photo
		WHERE id = @id	
	
		/*UPDATE GROCERY_PRODUCT
		SET author=@author, title=@title, edition=@edition, editorial=@editorial, year=@year
		WHERE id=@id*/
	END
GO
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_DeleteProduct]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_DeleteProduct]
END
GO
CREATE PROCEDURE dbo.usp_DeleteProduct(
	@id INT
 ) AS 
	BEGIN
		UPDATE PRODUCT
		SET status='I'
		WHERE id = @id	
	END
GO

/*HEALTHCARE*/

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddHealthCare]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddHealthCare]
END
GO
CREATE PROCEDURE dbo.usp_AddHealthCare(
	@name VARCHAR(250),
	@description VARCHAR(500),
	@price DECIMAL(10,2),
	@stockTotal	 INT,
	@brand VARCHAR(50),
	@quantitySold INT,
	@photo IMAGE,
	@id INT OUT
 ) AS 
	BEGIN
		INSERT INTO PRODUCT(name, description, price, stockTotal, status, photo, brand, quantitySold)
		SELECT @name, @description, @price, @stockTotal,'A', @photo, @brand, @quantitySold
		SET @id = SCOPE_IDENTITY()	
	
		INSERT INTO HEALTHCARE_PRODUCT(id)
		SELECT @id
	END
GO

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_UpdateHealthCare]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_UpdateHealthCare]
END
GO
CREATE PROCEDURE dbo.usp_UpdateHealthCare(
	@name VARCHAR(250),
	@description VARCHAR(500),
	@price DECIMAL(10,2),
	@stockTotal INT,
	@status CHAR (1),
	@brand VARCHAR (50),
	@quantitySold INT,
	@photo IMAGE,
	@id INT
 ) AS 
	BEGIN
		UPDATE PRODUCT
		SET name=@name, description=@description, price=@price, stockTotal=@stockTotal, status=@status, brand=@brand, quantitySold=@quantitySold, photo=@photo
		WHERE id = @id	
	
		/*UPDATE BOOK_PRODUCT
		SET author=@author, title=@title, edition=@edition, editorial=@editorial, year=@year
		WHERE id=@id*/ 
	END
GO

/*QUERY PRODUCTS*/ 

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllGroceries]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllGroceries]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllGroceries
AS
	SELECT * 
	FROM PRODUCT p, GROCERY_PRODUCT bp
	WHERE p.id = bp.id AND p.status='A'
	ORDER BY name
GO
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryGroceriesById]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryGroceriesById]
END
GO
CREATE PROCEDURE dbo.usp_QueryGroceriesById(@id INT)
AS
	SELECT * 
	FROM PRODUCT p, GROCERY_PRODUCT bp
	WHERE p.id= @id AND p.id = bp.id
GO				
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllHealthCare]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllHealthCare]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllHealthCare
AS
	SELECT * FROM PRODUCT p, HEALTHCARE_PRODUCT bp
	WHERE p.id = bp.id AND p.status='A'
	ORDER BY name
GO		
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryHealthCareById]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryHealthCareById]
END
GO
CREATE PROCEDURE dbo.usp_QueryHealthCareById(@id INT)
AS
	SELECT * FROM PRODUCT p, HEALTHCARE_PRODUCT bp
	WHERE p.id = @id AND p.id = bp.id
GO

/*RegisterSale*/

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_RegisterSale]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_RegisterSale]
END
GO
CREATE PROCEDURE dbo.usp_RegisterSale(
	@status CHAR(1),
	@date DATE,
	@paymentType CHAR(8),
	@arrivalTime INT,
	@deliveryManRating INT,
	@customerRating INT,
	@ubication VARCHAR(25),
	@total DECIMAL(10,2),
	@customer_id INT,
	@deliveryMan_id INT,
	@id INT OUT
) AS
	BEGIN
		INSERT INTO ORDER_S(status, date, paymentType, arrivalTime, deliveryManRating, customerRating, ubication, total, customer_id, deliveryMan_id)
		SELECT @status, @date, @paymentType, @arrivalTime, @deliveryManRating, @customerRating, @ubication, @total, @customer_id, @deliveryMan_id
		
		SET @id = SCOPE_IDENTITY()
	END
GO

/*AddSaleDetail*/

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_AddSaleDetail]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_AddSaleDetail]
END    
GO
CREATE PROCEDURE dbo.usp_AddSaleDetail(
	@order_id INT,
	@product_id INT,
	@quantity INT,
	@unit_price DECIMAL(10,2),
	@subtotal DECIMAL(10,2),
	@total DECIMAL(10,2),
	@id INT OUT
) AS
	BEGIN
		INSERT INTO SALE_DETAIL(order_id, product_id, quantity, unit_price, subtotal, total)
		SELECT @order_id, @product_id, @quantity, @unit_price, @subtotal, @total
		
		SET @id = SCOPE_IDENTITY()
	END
GO	

/*QueryAllProductsByName*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllProductsByName]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllProductsByName]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllProductsByName(
	@product_name VARCHAR(250)
)
AS
	SELECT * 
	FROM PRODUCT P
	FULL OUTER JOIN GROCERY_PRODUCT B ON B.id = P.id
	FULL OUTER JOIN HEALTHCARE_PRODUCT E ON E.id = P.id
	WHERE P.name LIKE '%' + @product_name + '%'
	ORDER BY name
GO

/*QueryAllGroceriesByCoincidence*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllGroceriesByCoincidence]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllGroceriesByCoincidence]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllGroceriesByCoincidence(
	@data VARCHAR(250)
)
AS
	SELECT 
		* 
	FROM 
		GROCERY_PRODUCT bp, PRODUCT p
	WHERE	
		   (p.name LIKE '%' + @data + '%' OR
			p.brand LIKE '%' + @data + '%' OR
			p.description LIKE '%' + @data + '%') AND
			bp.id = p.id
	ORDER BY name
GO	

/*QueryAllHealthCareByCoincidence*/
IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllHealthCareByCoincidence]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllHealthCareByCoincidence]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllHealthCareByCoincidence(
	@data VARCHAR(250)
)
AS
	SELECT * FROM HEALTHCARE_PRODUCT ep, PRODUCT p
	WHERE  (p.brand LIKE '%' + @data + '%' OR
			p.name LIKE '%' + @data + '%' OR
			p.description LIKE '%' + @data + '%') AND
			ep.id = p.id			
	ORDER BY name
GO

/*QueryAllProductsByCoincidence*/

IF EXISTS ( SELECT * 
            FROM   sysobjects 
            WHERE  id = object_id(N'[dbo].[usp_QueryAllProductsByCoincidence]') 
                   and OBJECTPROPERTY(id, N'IsProcedure') = 1 )
BEGIN
    DROP PROCEDURE [dbo].[usp_QueryAllProductsByCoincidence]
END
GO
CREATE PROCEDURE dbo.usp_QueryAllProductsByCoincidence(
	@data VARCHAR(250)
)

AS
	SELECT * FROM PRODUCT p
	WHERE  (p.brand LIKE '%' + @data + '%' OR
			p.name LIKE '%' + @data + '%' OR
			p.description LIKE '%' + @data + '%') 	
	ORDER BY name
GO


