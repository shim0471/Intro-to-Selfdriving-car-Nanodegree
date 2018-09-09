import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1.0
        return I

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])

    #
    # Primary matrix math methods
    #############################
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
            
        # In a 2x2 martix, if ad = bc, then the matrix does not have an inverse
        if (self.g[0][0] * self.g[1][1]) == (self.g[0][1] * self.g[1][0]):
            raise(NotImplementedError, "Not implemented Because ad = bc.")
        
        # Calculate ad - bc from equation in the lesson.
        det = ((self.g[0][0] * self.g[1][1]) - (self.g[0][1] * self.g[1][0]))
     
        return det
        

    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        # Define total sum of diagonal elements
        trace_sum = 0
        
        if not self.is_square():
            raise(ValueError, "Cannot calculate the trace of a non-square matrix.")
            
        # Sum elements on th main diagonal of the matrix
        for i in range(len(self.g)):
            for j in range(len(self.g)):
                if i == j:
                    trace_sum += self.g[i][j]
                    
        return trace_sum

        
    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")
            
        # Store the result in the empty list
        inverse_result = []
        
        # For 1x1 matrix with single element with value a, then inverse 1 / a.
        if self.h == 1:
            for row in self.g:
                for col in row:
                     inverse_result.append([1 / col])
                        
        # If the matrix is 2x2, check that the matrix is invertible
        else:
            det_result = self.determinant()    # Store the result of determinant function()
            
            # If 2x2 matirx has ad-bc = 0, then return Error message!
            if det_result == 0:
                raise(ValueError, "Matrix has no inverse.")
            
            # Store the result of 1 / ad-bc.
            division = 1/det_result
            
            # Store outputs of the matrix inverse to empty list.
            for i in range(self.h):
                if i == 0: # First row
                    inverse_result.append([self.g[1][1] * division , (-1 * self.g[0][1]) * division])
                elif i == 1: # Second row
                    inverse_result.append([(-1 * self.g[1][0]) * division, self.g[0][0] * division])
       
        return Matrix(inverse_result)

    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
       
        # Define the empty list to store the result
        transposed=[]
        
        # Iterate through the rows of matrix then take the transpose as switching rows and columns.
        for i in range(self.w):
            row_result = []
            for row in self.g:
                row_result.append(row[i])
            transposed.append(row_result)
        
        return Matrix(transposed)
        
        
    # Check matrix size
    def is_square(self):
        return self.h == self.w
    

    #
    # Begin Operator Overloading
    ############################
    def __getitem__(self,idx):
        """
        Defines the behavior of using square brackets [] on instances
        of this class.

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > my_matrix[0]
          [1, 2]

        > my_matrix[0][0]
          1
        """
        return self.g[idx]

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
            
        # Define the empty list   
        sum_result = []
        
        # Matrix addition is an element by element operation with other matrix.
        for i in range(self.h):
            row_result = []    # initialize the row list.
            for j in range(self.w):
                row_result.append(self[i][j] + other[i][j])
            sum_result.append(row_result)    # Add the result after two elements sum.
            
        return Matrix(sum_result)

    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        # Define the empty list
        neg_result = []
        
        # 
        for row in self.g:
            row_result = [] # initialize the row list.
            for col in row:
                row_result.append(-col)
            neg_result.append(row_result) # Add the negative result to the neg_result list.
            
        return Matrix(neg_result)

    def __sub__(self, other):
        """
        Defines the behavior of - operator (as subtraction)
        """
        # Define the empty list
        sub_result = []
        
        # Matrix subtraction is an element by element operation with other matrix.
        for i in range(self.h):
            row_result = []    # initialize the row list.
            for j in range(self.w):
                row_result.append(self[i][j] - other[i][j])
            sub_result.append(row_result)    # Add the result after two elements subtraction.
            
        return Matrix(sub_result)
        

    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        # Define the empty list
        product = []
        
        # Assigned the transposed matrix from previous T function.
        transposed_other = other.T()
        
        # Calculating the dot product of a row from self matrix with a column from other matrix.
        def dot_product(row, col):
            result = 0
            
            for i in range(len(row)):
                result += row[i] * col[i]
            
            return result
        
        # Takes two matrices and multiplies them together and return the result.
        for row in self:
            matrix_product = []    # initialize the row list
            for col in transposed_other:
                matrix_product.append(dot_product(row, col)) # Add the dot product result to an empty list called matrix_product
                
            product.append(matrix_product) # After interating through all of the columns in other matrix, 
                                           # add results to product empty list.
                
        return Matrix(product)
              
        
    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
        if isinstance(other, numbers.Number):
            pass
            #   
            # Define empty list.
            rmul_result = []
            
            # Iterate through rows and columns, then multiplying a matrix with an identity matrix.
            for row in self.g:
                row_result = [] 
                for col in row:
                    row_result.append(col * other)
                rmul_result.append(row_result)
            
            return Matrix(rmul_result)
        
                        
    
            