#include <iostream>
#include <vector>
using namespace std;
enum PieceColor{BLACK, WHITE};   
class PiecePos{
    private:
        int x;
        int y;
    public:
        PiecePos(int a,int b):x(a),y(b){} 
        int getX(){return x;}
        int getY(){return y;}
};
class Piece{
    protected:
        PieceColor m_color;
        PiecePos m_pos;
    public:
        Piece(PieceColor color,PiecePos pos):m_color(color),m_pos(pos){}
        // (1);
        virtual void Draw()=0;
};
class BlackPiece:public Piece{
    public:
        BlackPiece(PieceColor color,PiecePos pos):Piece(color,pos){}
        void Draw(){cout<<"draw a black piece"<<endl;}

};
class WhitePiece:public Piece{
    public:
    WhitePiece(PieceColor color,PiecePos pos):Piece(color,pos){}
    void Draw(){cout<<"draw a white piece"<<endl;}
};
class PieceBoard{
    private:
        // vector<(2)> m_vecPiece;
        vector<Piece*> m_vecPiece;
        string m_blackName;
        string m_whiteName;
    public:
        PieceBoard(string black,string white):m_blackName(black),m_whiteName(white){}
        void SetPiece(PieceColor color,PiecePos pos){
            // (3)piece=nullptr;
            Piece* piece=nullptr;
            if(color=BLACK)
            {
                piece=new BlackPiece(color,pos);
                cout<<m_blackName <<"in position(" <<pos.getX() <<","<<pos.getY()<< ")";
                // (4)
                piece->Draw();
            }
            else
            {  

                piece=new WhitePiece(color,pos);  

                cout<<m_whiteName <<"in position(" <<pos.getX() <<","<<pos.getY()<< ")";

                // (  5  );

                piece->Draw();

             }
             m_vecPiece.push_back(piece);
        }

};

int main() {

    PieceBoard board("BlackPlayer", "WhitePlayer");

    // Add pieces to the board.
    board.SetPiece(BLACK, PiecePos(1, 1));
    board.SetPiece(WHITE, PiecePos(2, 2));

    // Attempt to reuse a black piece object.
    board.SetPiece(BLACK, PiecePos(3, 3));

    // Add more pieces as desired...

    return 0;
}
