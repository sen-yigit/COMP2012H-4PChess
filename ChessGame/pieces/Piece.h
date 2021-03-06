//The Piece class is an abstract base class defined for all pieces on the chess board
// It contains references to the Game and Player objects so we may access:
// which Player owns the Piece and
// the position of the Piece on the board.

#ifndef INC_4PCHESS_PIECE_H
#define INC_4PCHESS_PIECE_H

#include <string>
#include "../Player.h"
#include <vector>

class Game;

class Player;

class Piece {

    protected:
        explicit Piece(Player &player, Game &game, int x, int y);

        Player &player;
        Game &game;
        bool is_captured;
        int points;
        bool has_moved = false;
        int x;
        int y;
        int possible_moves[14][14];

    public:
        enum class Type {
            BISHOP = 1,
            KING = 2,
            KNIGHT = 3,
            PAWN = 4,
            QUEEN = 5,
            ROOK = 6
        };

        struct Coordinates {
            int x;
            int y;
        };

        int getX();
        int getY();

        void setX_0();
        void setY_0();

        int which_player();

        void setCoordinates(int x, int y);

        virtual ~Piece() = default;

        bool get_is_captured();
        void set_is_captured(bool);

        virtual Piece::Type get_type() const = 0;

        virtual int get_point() const = 0;
        void set_points(int);

        virtual int list_possible_moves() = 0;

        int get_possible_move_at(int x, int y);
        void set_possible_move_at(int x, int y, int value);

        bool get_has_moved();
        void set_has_moved(bool);

        virtual std::string get_img() const = 0;

        std::vector <Piece::Coordinates> get_moves_vec();
};


#endif //INC_4PCHESS_PIECE_H
