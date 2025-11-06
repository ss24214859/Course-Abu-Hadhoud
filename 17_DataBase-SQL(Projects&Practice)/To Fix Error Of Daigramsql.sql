Restore database HR_Database
from disk = 'C:\HR_Database.bak'

use HR_Database
exec sp_Changedbowner 'sa';