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
    @iid INT OUT /*analizar bien para que no bote error*/
 ) AS 
	BEGIN
		INSERT INTO APP_USER (username, password, first_name, last_name, gender, 
								document_number, phone_number, address, email, category)
		SELECT 	@vusername, @vpassword, @vfirst_name, @vlast_name, @cgender, 
				@vdocument_number, @vphone_number, @vaddress, @vemail, @vcategory

		SET @iid = SCOPE_IDENTITY()	
	END
GO